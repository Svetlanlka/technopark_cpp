#ifndef TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_

#define SIZE 1024
#define TIME_LIMIT 59
#define LIMIT_HOURS_OF_DAY 23
#define ERROR_WITH_FILENAME -1
#define ERROR_STR_POINTER -2
#define WRONG_DATE_FORMAT -3
#define INPUT_ERROR -4
#define MEMORY_ALLOCATION_ERROR -5

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "string.h"

char** read_data_from_file(const char *filename);
char** input_data();
char** date_filter(const char **str, int *count);
int print_correct_dates(const char **str, int count);

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_FILTER_H_
