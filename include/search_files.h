#ifndef TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_

#define SIZE 256
#define TOP_SIZE 5
#define FILES_COUNT 500
#define PROGRAM_ERROR -1
#define INPUT_ERROR -4
#define SEARCH_LOG 0
#define SORT_LOG 0

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "string.h"
#include "dirent.h"

struct File_info {
    char *filepath;
    int count;
};

struct File_search {
    char * query;
    size_t query_size;
    //File_info top_files[TOP_SIZE];

    /*File_search(char * new_query = NULL, size_t new_query_size = 0) :query(new_query), query_size(new_query_size) {};
    int get_query() { return query; }
    int get_query_size() { return query_size; }
    void Add(File_info new_file_info) {
        for (size_t i = 0; i < query_size; ++i) {
            if (new_file_info.count > top_files[i].count) {
                for (size_t j = i + 1; j < query_size; ++j)
                    if (!j) top_files[j] = top_files[j - 1];
                top_files[i] = new_file_info;
            }
        }
    }*/
};

int read_directory (const char * dir_name, char ** arr_of_files, int * files_count);
struct File_info* sorting_files (char **arr_of_files, int * count_files, struct File_search * search_data);
int print_top_of_files(struct File_info *sorted_files, int count_files);
int search_in_file (const char * filepath, struct File_search * search_data);

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
