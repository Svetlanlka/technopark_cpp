#ifndef TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_
#define TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_

#define LOG_MEMORY 0
#define PARSER_LOG 1
#define SIZE 1024
#define INPUT_FILE "../test/test_cases/test4.txt"
//#define INPUT_FILE "test_file.txt"

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

#endif  // TECHNOPARK_CPP_INCLUDE_DATE_PARSER_H_