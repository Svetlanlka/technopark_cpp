#ifndef TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_

#define SIZE 1024
#define TIME_LIMIT 59
#define LIMIT_HOURS_OF_DAY 23
#define INPUT_FILE "../unit_tests/test4.txt"
#define ERROR_WITH_FILENAME -1
#define ERROR_STR_POINTER -2
#define WRONG_DATE_FORMAT -3
#define INPUT_ERROR -4

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int Date_parser(const char *filename, int check); // ввод строк с датой и вызов Date_str_parser

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
