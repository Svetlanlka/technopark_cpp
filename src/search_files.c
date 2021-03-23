#include <stdlib.h>
#include <stdio.h>

#include "search_files.h"

// обход всех файлов и составление списка файлов со всех папок внутри этой директории
int read_directory(const char *dir_name, char **arr_of_files, int *files_count) {
    if (SEARCH_LOG) printf("read directory: %s\n", dir_name);
    if (!dir_name) return NULL_POINTER_ERROR;
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
                strcpy(arr_of_files[*files_count], cur_dir_name);
                (*files_count)++;
            }
        }
    }

    closedir(dir);
    return 0;
}

struct File_info * sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data) {
    if (SEARCH_LOG) printf("Ordinary search and sorting files\n");
    struct File_info * sorted_files = malloc(sizeof(struct File_info)* (*count_files));

    for (size_t i = 0; i < *count_files; ++i) {
        int new_count = search_in_file(arr_of_files[i], search_data);
        if (SEARCH_LOG)
            printf("\nSearch in file[%zu]: %s\nCOUNT: %d\n", i, arr_of_files[i], new_count);

        // заполнение массива в отсортированном виде
        insert_new_filepath(sorted_files, new_count, arr_of_files, i);
    }

    return sorted_files;
}

int print_top_of_files(struct File_info *sorted_files, int count_files) {
    if (!sorted_files) return NULL_POINTER_ERROR;

    for (size_t i = 0; i < count_files; i++)
        printf("%zu. FILE: %s, COUNT: %d\n", i + 1, sorted_files[i].filepath, sorted_files[i].count);

    return 0;
}

int insert_new_filepath (struct File_info * sorted_files, int new_count, char **arr_of_files, int cur_number) {
    size_t j = 0;
    for (; j < cur_number; ++j) {
        if (new_count > sorted_files[j].count /*|| j == cur_number*/) {
            for (size_t k = cur_number /*&& j != cur_number*/; k > j; --k) {
                sorted_files[k].filepath = sorted_files[k - 1].filepath;
                sorted_files[k].count = sorted_files[k - 1].count;
                //if (SORT_LOG) printf("ADD[%zu]: %s\n", k, sorted_files[k].filepath);
            }
            sorted_files[j].filepath = arr_of_files[cur_number];
            sorted_files[j].count = new_count;
            break;
        }
    }
    if (j == cur_number) {
        sorted_files[j].filepath = arr_of_files[cur_number];
        sorted_files[j].count = new_count;
    }
    return 0;
}

int search_in_file (const char * filepath, struct File_search * search_data) {
    if (!filepath) return NULL_POINTER_ERROR;

    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        return OPEN_FILE_ERROR;
    }

    int count = 0;
    char input_text[search_data->query_size + 2]; // + 2 - на '\0' и новый вводимый символ
    input_text[search_data->query_size] = '\0';

    size_t i = 0;
    for (; i < search_data->query_size; ++i)
        fread(&input_text[i], sizeof(char), 1, file);
    input_text[search_data->query_size] = '\0';

    // не найдено, кол-во символов в запросе больше кол-ва символов в файле
    if (i != search_data->query_size) {
        fclose(file);
        return 0;
    }
    else if (!strcmp(input_text, search_data->query)) count++;

    char input_sim = '\0';
    while (fread(&input_sim, sizeof(char), 1, file) == 1) {
        input_text[search_data->query_size] = input_sim;
        input_text[search_data->query_size + 1] = '\0';

        memmove(&input_text[0], &input_text[1], search_data->query_size);
        input_text[search_data->query_size] = '\0';
        if (!strcmp(input_text, search_data->query)) count++;
    }

    fclose(file);
    return count;
}