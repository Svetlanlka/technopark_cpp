#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <dlfcn.h>
#include <time.h>
#include <string.h>

#include "search_files.h"

// Пример ввода: ./technopark_cpp "../testing_directory" cpp
// То есть: exe-шник директория запрос
void free_all(char **arr_of_files, file_info * sorted_files, int argc, char * query, void *ext_library, int files_count) {
    if (arr_of_files) free_arr(arr_of_files, files_count);
    if (arr_of_files) free(arr_of_files);
    if (sorted_files) free(sorted_files);
    if (argc < 3 && query) free(query);
    if (ext_library) dlclose(ext_library);
}

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
        if (!query) {
            free(query);
            return MEMORY_ERROR;
        }

        while((query[i] = getchar()) != '\0' && query[i] != '\n') i++;
        query[i] = '\0';
    }

    file_search search_data  = {query, i};
    if (MAIN_LOG) printf("query: %s, size of query: %zu\n", search_data.query, search_data.query_size);
    char **arr_of_files = malloc (sizeof(char *) * FILES_COUNT);
    if (!arr_of_files) {
        free_all(arr_of_files, NULL, argc, query, NULL, 0);
        return MEMORY_ERROR;
    }
    int files_count = 0;

    void *ext_library;
    int (*print_files)(file_info *sorted_files, int count_files);
    int (*read_dir)(const char * dir_name, char ** arr_of_files, int * files_count);
    file_info* (*sort)(char **arr_of_files, int * count_files, file_search * search_data);
    file_info* (*parallel_sort)(char **arr_of_files, int * count_files, file_search * search_data);
    ext_library = dlopen("./libtp_library_dynamic.so", RTLD_LAZY);
    if (!ext_library) {
        free_all(arr_of_files, NULL, argc, query, ext_library, files_count);
        return LIBRARY_OPEN_ERROR;
    }

    read_dir = dlsym(ext_library, "read_directory");
    if ((*read_dir)(argv[1], arr_of_files, &files_count) != 0) {
        free_all(arr_of_files, NULL, argc, query, ext_library, files_count);
        return PROGRAM_ERROR;
    }

    file_info *sorted_files = NULL;
    clock_t start = clock();
    if (argc == 4) {
        printf("PARALLEL SEARCH!\n");
        parallel_sort = dlsym(ext_library, "parallel_sorting_files");
        if (!parallel_sort) {
            free_all(arr_of_files, sorted_files, argc, query, ext_library, files_count);
            return LIBRARY_OPEN_ERROR;
        }
        sorted_files = (*parallel_sort)(arr_of_files, &files_count, &search_data);
    } else {
        printf("USUAL SEARCH!\n");
        sort = dlsym(ext_library, "sorting_files");
        if (!sort) {
            free_all(arr_of_files, sorted_files, argc, query, ext_library, files_count);
            return LIBRARY_OPEN_ERROR;
        }
        sorted_files = (*sort)(arr_of_files, &files_count, &search_data);
    }
    clock_t end = clock();
    printf("\nTIME: %f\n", (float)(end - start) / CLOCKS_PER_SEC);
    printf("\nTOP %d files:\n", TOP_SIZE);

    print_files = dlsym(ext_library, "print_top_of_files");//(sorted_files, files_count < TOP_SIZE ? files_count : TOP_SIZE);
    if (!print_files) {
        free_all(arr_of_files, sorted_files, argc, query, ext_library, files_count);
        return LIBRARY_OPEN_ERROR;
    }
    if (files_count) (*print_files)(sorted_files, files_count < TOP_SIZE ? files_count : TOP_SIZE);

    free_all(arr_of_files, sorted_files, argc, query, ext_library, files_count);
    pthread_exit(NULL);
    return 0;
}