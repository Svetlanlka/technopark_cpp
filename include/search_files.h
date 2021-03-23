#ifndef TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_
#define TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_

#define SIZE 256
#define TOP_SIZE 5
#define FILES_COUNT 500
#define COUNT_CPU 4
#define PROGRAM_ERROR -1
#define NULL_POINTER_ERROR -2
#define OPEN_FILE_ERROR -3
#define INPUT_ERROR -4
#define SEARCH_LOG 1
#define PARALLEL_SEARCH_LOG 1

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "string.h"
#include "dirent.h"
#include <pthread.h>
#include <time.h>
#include "unistd.h"

struct File_info {
    char *filepath;
    int count;
};

struct File_search {
    char * query;
    size_t query_size;
};

int read_directory (const char * dir_name, char ** arr_of_files, int * files_count);
struct File_info* sorting_files (char **arr_of_files, int * count_files, struct File_search * search_data);
int print_top_of_files(struct File_info *sorted_files, int count_files);

int search_in_file (const char * filepath, struct File_search * search_data);
int insert_new_filepath (struct File_info * sorted_files, int new_count, char **arr_of_files, int cur_number);

struct File_info * parallel_sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data);

#endif  // TECHNOPARK_CPP_INCLUDE_SEARCH_FILES_H_
