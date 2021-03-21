#include <stdlib.h>
#include <stdio.h>

#include "search_files.h"


int main(int argc, char *argv[]) {
    if (argc > 2) return INPUT_ERROR;

    printf("Ocheretnaya Svetlana. APO-13\nEnter query to search: ");

    char query[SIZE];
    size_t i = 0;
    while((query[i] = getchar()) != '\0' && query[i] != '\n') i++;
    query[i] = '\0';

    struct File_search search_data  = {query, i};

    if (SEARCH_LOG) printf("query: %s, size of query: %zu\n", search_data.query, search_data.query_size);

    char **arr_of_files = malloc (sizeof(char *) * FILES_COUNT);
    int files_count = 0;
    if (read_directory(argv[1], arr_of_files, &files_count) != 0) return PROGRAM_ERROR;
//    for (size_t j = 0; j < files_count; j++)
//        printf("file[%zu]: %s\n", j, arr_of_files[j]);

    struct File_info * sorted_files = sorting_files(arr_of_files, &files_count, &search_data);
    printf("TOP %d files:\n", TOP_SIZE);
    print_top_of_files(sorted_files, TOP_SIZE);

    for (size_t j = 0; j < files_count; ++j)
        free(arr_of_files[j]);
    free(arr_of_files);

    return 0;
}
