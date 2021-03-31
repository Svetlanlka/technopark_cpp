#include "search_files.h"
#include "my_library_search_files.h"

// обход всех файлов и составление списка файлов со всех папок внутри этой директории
int read_directory(const char *dir_name, char **arr_of_files, int *files_count) {
    if (!dir_name || !arr_of_files || !files_count) return NULL_POINTER_ERROR;

    DIR *dir = opendir(dir_name);
    if (!dir) {
        closedir(dir);
        return OPEN_FILE_ERROR;
    }
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
            DIR *tmp_dir = opendir(cur_dir_name);
            if (tmp_dir) {
                if (SEARCH_LOG) printf("DIR: %s\n", cur_dir_name);
                read_directory(cur_dir_name, arr_of_files, files_count);
                closedir(tmp_dir);
            } else {
                if (SEARCH_LOG) printf("File: %s\n", cur_dir_name);
                arr_of_files[*files_count] = malloc (sizeof(char *) * SIZE);
                if (!arr_of_files[*files_count]) return MEMORY_ERROR;

                strcpy(arr_of_files[*files_count], cur_dir_name);
                (*files_count)++;
            }
        }
    }

    closedir(dir);
    return 0;
}

int print_top_of_files(file_info *sorted_files, int count_files) {
    if (!sorted_files) return NULL_POINTER_ERROR;

    for (size_t i = 0; i < count_files; i++)
        printf("%zu. FILE: %s, COUNT: %d\n", i + 1, sorted_files[i].filepath, sorted_files[i].count);

    return 0;
}

void free_arr(char ** arr, int size) {
    for (size_t i = 0; i < size; ++i)
        free(arr[i]);
}