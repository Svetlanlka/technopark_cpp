#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "search_files.h"

// Пример ввода: ./technopark_cpp "../testing_directory" cpp
// То есть: exe-шник директория запрос

int main(int argc, char *argv[]) {
    if (argc > 4) return INPUT_ERROR;

    // ввод запроса для поиска
    printf("Ocheretnaya Svetlana. APO-13\nEnter query to search: ");

    size_t i = 0;
    char *query = NULL;
    if (argc >= 3) {
        query = argv[2];
        i = strlen(argv[2]);
    } else {
        query = malloc(sizeof(char) * SIZE);
        if (!query) return MEMORY_ERROR;

        while((query[i] = getchar()) != '\0' && query[i] != '\n') i++;
        query[i] = '\0';
    }

    file_search search_data  = {query, i};
    if (MAIN_LOG) printf("query: %s, size of query: %zu\n", search_data.query, search_data.query_size);
    char **arr_of_files = malloc (sizeof(char *) * FILES_COUNT);
    if (!arr_of_files) return MEMORY_ERROR;
    int files_count = 0;

    if (read_directory(argv[1], arr_of_files, &files_count) != 0) return PROGRAM_ERROR;

    if (MAIN_LOG) {
        for (size_t j = 0; j < files_count; j++)
            printf("file[%zu]: %s\n", j, arr_of_files[j]);
    }

    file_info *sorted_files = NULL;
    clock_t start = clock();
    if (argc == 4) {
        printf("PARALLEL SEARCH!\n");
         sorted_files = parallel_sorting_files(arr_of_files, &files_count, &search_data);
    } else {
        printf("USUAL SEARCH!\n");
        sorted_files = sorting_files(arr_of_files, &files_count, &search_data);
    }
    clock_t end = clock();
    printf("\nTIME: %f\n", (float)(end - start) / CLOCKS_PER_SEC);
    printf("\nTOP %d files:\n", TOP_SIZE);
    if (files_count) print_top_of_files(sorted_files, files_count < TOP_SIZE ? files_count : TOP_SIZE);

    // освобождение памяти
    free_arr(arr_of_files, files_count);
    free(arr_of_files);
    free(sorted_files);
    if (argc < 3) free(query);

    pthread_exit(NULL);
    return 0;
}
