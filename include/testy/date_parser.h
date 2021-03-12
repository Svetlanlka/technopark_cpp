#ifndef TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_

#define LOG_MEMORY 0
#define PARSER_LOG 1
#define SIZE 1024
#define INPUT_FILE "../test/test_cases/test4.txt"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct Dates {
    char **arr_dates; // массив правильных дат
    int el_count; // колличество правильных дат
    int colon_count; // текущее кол-во двоеточий
    int count_sym; // текущее кол-во символов, пока не встретилось следующее двоеточие
};

int Date_parser(char ** str, size_t size, struct Dates *dates);
int Date_sym_parser(const char *str, struct Dates *dates);

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_