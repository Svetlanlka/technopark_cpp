#ifndef TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_
#define TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_

#define SIZE 256
#define TOP_SIZE 5
#define FILES_COUNT 500
#define COUNT_CPU 1
#define PROGRAM_ERROR 1
#define NULL_POINTER_ERROR 2
#define OPEN_FILE_ERROR 3
#define INPUT_ERROR 4
#define MEMORY_ERROR 5
#define LIBRARY_OPEN_ERROR 6
#define MAIN_LOG 0

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    char *filepath;
    int count;
} file_info;

typedef struct {
    char * query;
    size_t query_size;
} file_search;

int read_directory (const char * dir_name, char ** arr_of_files, int * files_count);
file_info* sorting_files (char **arr_of_files, int * count_files, file_search * search_data);
int print_top_of_files(file_info *sorted_files, int count_files);

file_info * parallel_sorting_files(char **arr_of_files, int * count_files, file_search * search_data);
void free_arr(char ** arr, int size);

#endif  // TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_
