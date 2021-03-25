#ifndef TECHNOPARK_CPP_MY_LIBRARY_INCLUDE_SEARCH_FILES_H_
#define TECHNOPARK_CPP_MY_LIBRARY_INCLUDE_SEARCH_FILES_H_

#define SEARCH_LOG 0
#define PARALLEL_SEARCH_LOG 0

#include <search_files.h>

int search_in_file (const char * filepath, struct File_search * search_data);
int insert_new_filepath (struct File_info * sorted_files, int new_count, char **arr_of_files, int cur_number);

#endif  // TECHNOPARK_CPP_INCLUDE_MY_LIBRARY_SEARCH_FILES_H_