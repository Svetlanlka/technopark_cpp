#include <stdlib.h>
#include <stdio.h>

#include "search_files.h"

int read_directory(const char *dir_name, int level) {
    if (SEARCH_LOG) printf("read directory: %s\n", dir_name);
    if (!level || !dir_name) return INPUT_ERROR;
    DIR *dir = opendir(dir_name);
    if (!dir)
        return INPUT_ERROR;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) { // если . или .. продолжить обход
            continue;
        } else {
            char cur_dir_name[SIZE];
            cur_dir_name[0] = '\0';
            strcat(cur_dir_name, dir_name);
            strcat(cur_dir_name, "/");
            strcat(cur_dir_name, entry->d_name);
            if (opendir(cur_dir_name)) {
                read_directory(cur_dir_name, level - 1);
            } else {
                if (SEARCH_LOG) printf("current dir: %s\n", entry->d_name);
                search_in_file(entry->d_name);
            }
        }
    }
    closedir(dir);
    return 0;
}

int search_in_file (const char *filename) {
    if (!filename) return INPUT_ERROR;
    if (SEARCH_LOG) printf("Search in file: %s\n", filename);
    return 0;
}

/*char** read_data_from_file(const char *filename) {
    if (!filename) return NULL;

    FILE *file = NULL;
    file = fopen(filename, "r");
    if (!file) return NULL;

    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    if (!input_text) {
        fclose(file);
        return NULL;
    }

    size_t i = 0;
    while ((input_text[i] =  enter_new_data(file, 1)) != NULL) i++;

    fclose(file);

    return input_text;
}*/
