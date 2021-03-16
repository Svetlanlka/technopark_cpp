#include <stdlib.h>
#include <stdio.h>

#include "date_parser.h"

struct Dates {
    char **arr_dates; // массив правильных дат
    int el_count; // колличество правильных дат
    int colon_count; // текущее кол-во двоеточий
    int count_sym; // текущее кол-во символов, пока не встретилось следующее двоеточие
};

int Date_str_parser(char ** str, size_t size, struct Dates *dates); // вызов в цикле Date_sym_parser для каждой строки с датой
int Date_sym_parser(const char *str, struct Dates *dates); // Парсинг посимвольно каждой строки с датой
char* Enter_new_data (FILE *file, int check);


int Date_parser(const char *filename, int check) {
    if (!filename && check == 1) return ERROR_WITH_FILENAME;

    FILE *file = NULL;
    if (check == 1)
        file = fopen(filename, "r");
    if (!file && check == 1) return ERROR_WITH_FILENAME;

    struct Dates dates = { NULL, 0, 0, 0 };

    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    dates.arr_dates = (char **) malloc(sizeof(char*) * SIZE);

    // ввод данных
    size_t i = 0;
    for (; (input_text[i] = Enter_new_data(file, check)) != NULL; i++) {}

    int count = Date_str_parser(input_text, i, &dates);

    // чистка памяти
    for (size_t j = 0; j < i; j++) {
        free(input_text[j]);
    }
    free(input_text);

    for (int j = 0; j < dates.el_count; j++) {
        free(dates.arr_dates[j]);
    }
    free(dates.arr_dates);

    if (check == 1) fclose(file);
    return count;
}

char *Enter_new_data (FILE *file, int check) {
    if (check == 1 && !file) return NULL;

    char *chunk = (char *) malloc(sizeof(char) * SIZE); // при больших строках size увеличится
    if (check == 1) {
        if (fscanf(file, "%1024s", chunk) != 1) {
            free(chunk);
            return NULL;
        }
    } else {
        if (scanf("%1024s", chunk) != 1) {
            if (!chunk)
                return NULL;
//            printf("%s", chunk);
            free(chunk);
            return NULL;
        }
    }

    return chunk;
}

// ПАРСИНГ СТРОК: Парсинг переданнного массива, который вводим или берем из файла в main
// (В цикле поочередно передаются все строки в функцию Date_sym_parser)
int Date_str_parser(char **str, size_t size, struct Dates *dates) {
    if (!str || !dates) return ERROR_STR_POINTER;

    for (size_t i = 0; i < size && str[i]; ++i) {
        char *date_str = (char *) malloc (sizeof(char) * SIZE * (size / SIZE + 1));

        if (Date_sym_parser(str[i], dates) != WRONG_DATE_FORMAT) {
            dates->arr_dates[dates->el_count++] = date_str;
        } else {
            free(date_str);
        }
    }

    return dates->el_count;
}

// Парсинг посимвольный
int Date_sym_parser(const char *str, struct Dates *dates) {
    if (!str || !dates) return ERROR_STR_POINTER;

    int cur_num = 0; // текущее значение (час 0-23/минута 0-59/секунда 0-59)
    dates->colon_count = 0;
    dates->count_sym = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && (int)str[i] <= '9') {
            cur_num = cur_num * 10 + (str[i] - '0');

            if (++dates->count_sym > 2)
                return WRONG_DATE_FORMAT;
            if ((dates->colon_count == 0 && cur_num > LIMIT_HOURS_OF_DAY) || (dates->colon_count != 0 && cur_num > TIME_LIMIT))
                return WRONG_DATE_FORMAT;
        } else if (str[i] == ':') {
            cur_num = 0;
            if (dates->count_sym != 2)
                return WRONG_DATE_FORMAT;
            dates->count_sym = 0;
            if (++dates->colon_count > 2)
                return WRONG_DATE_FORMAT;
        } else {
            return WRONG_DATE_FORMAT;
        }
    }

    if (dates->colon_count != 2)
        return WRONG_DATE_FORMAT;
    if (dates->count_sym == 0)
        return WRONG_DATE_FORMAT;
    return 0;
}
