#include <stdlib.h>
#include <stdio.h>

#include "search_files.h"
#include "my_library_search_files.h"

file_info * sorting_files(char **arr_of_files, int * count_files, file_search * search_data) {
    if (!arr_of_files || !search_data || !count_files) return NULL;

    file_info * sorted_files = malloc(sizeof(file_info)* (*count_files));
    if (!sorted_files) return NULL;

    for (size_t i = 0; i < *count_files; ++i) {
        int new_count = search_in_file(arr_of_files[i], search_data);
        if (new_count == OPEN_FILE_ERROR || new_count == NULL_POINTER_ERROR) {
            free(sorted_files);
            return NULL;
        }
        if (SEARCH_LOG) printf("\nSearch in file[%zu]: %s\nCOUNT: %d\n", i, arr_of_files[i], new_count);

        // заполнение массива в отсортированном виде
        if (insert_new_filepath(sorted_files, new_count, arr_of_files, i) == NULL_POINTER_ERROR) return NULL;
    }

    return sorted_files;
}

int insert_new_filepath (file_info * sorted_files, int new_count, char **arr_of_files, int cur_number) {
    if (!arr_of_files || !sorted_files) return NULL_POINTER_ERROR;

    size_t j = 0;
    for (; j < cur_number; ++j) {
        if (new_count > sorted_files[j].count) {
            for (size_t k = cur_number; k > j; --k) {
                sorted_files[k].filepath = sorted_files[k - 1].filepath;
                sorted_files[k].count = sorted_files[k - 1].count;
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

int search_in_file (const char * filepath, file_search * search_data) {
    if (!filepath || !search_data) return NULL_POINTER_ERROR;

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
    for (; i < search_data->query_size; ++i) {
        if (fread(&input_text[i], sizeof(char), 1, file) != 1) break;
    }
    input_text[search_data->query_size] = '\0';

    // не найдено, кол-во символов в запросе больше кол-ва символов в файле

    if (i != search_data->query_size) {
        fclose(file);
        return -10;
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