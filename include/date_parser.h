#ifndef TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_

#define SIZE 1024
#define TIME_LIMIT 59
#define LIMIT_HOURS_OF_DAY 23
#define INPUT_FILE "../unit_tests/test4.txt"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct Dates {
    char **arr_dates; // массив правильных дат
    int el_count; // колличество правильных дат
    int colon_count; // текущее кол-во двоеточий
    int count_sym; // текущее кол-во символов, пока не встретилось следующее двоеточие
};

int Date_parser(const char *filename, int check); // ввод строк с датой и вызов Date_str_parser
int Date_str_parser(char ** str, size_t size, struct Dates *dates); // вызов в цикле Date_sym_parser для каждой строки с датой
int Date_sym_parser(const char *str, struct Dates *dates); // Парсинг посимвольно каждой строки с датой
char* Enter_new_data (FILE *file, int check);

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
