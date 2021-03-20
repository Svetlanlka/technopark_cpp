#ifndef TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_

#define SIZE 256
#define PROGRAM_ERROR -1
#define INPUT_ERROR -4
#define SEARCH_LOG 1

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "string.h"
#include "dirent.h"

int read_directory(const char *dir_name, int level);
int search_in_file (const char *filename);

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
