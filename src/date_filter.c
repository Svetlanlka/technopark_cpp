#include <stdlib.h>
#include <stdio.h>

#include "date_filter.h"

struct Dates {
    char **arr_dates; // массив правильных дат
    int el_count; // колличество правильных дат
    int colon_count; // текущее кол-во двоеточий
    int count_sym; // текущее кол-во символов, пока не встретилось следующее двоеточие
};

int date_str_filter(const char ** str, struct Dates *dates); // вызов в цикле Date_sym_filter для каждой строки с датой
int date_sym_filter(const char *str, struct Dates *dates); // Фильтр посимвольно каждой строки с датой
char* enter_new_data (FILE *file, int check);

char** read_data_from_file(const char *filename) {
    if (!filename) return NULL;

    FILE *file = NULL;
    file = fopen(filename, "r");
    if (!file) return NULL;

    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    if (!input_text)
        return NULL;

    size_t i = 0;
    while ((input_text[i] =  enter_new_data(file, 1)) != NULL) i++;

    fclose(file);

    return input_text;
}

// Я все же сделала 2 отдельных функции на ввод из файла и чтение из консоли.
// Все таки так более целесообразно, одна функция - одна цель, без использования каких-то переменных-флагов
char** input_data() {
    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    if (!input_text)
        return NULL;

    // ввод данных
    size_t i = 0;
    while ((input_text[i] = enter_new_data(NULL, 0)) != NULL) i++;

    return input_text;
}

char** date_filter(const char **str, int *count) {
    if (!str) return NULL;

    struct Dates dates = { NULL, 0, 0, 0 };
    dates.arr_dates = (char **) malloc(sizeof(char*) * SIZE);
    if (!dates.arr_dates)
        return NULL;

    *count = date_str_filter(str, &dates);

    return dates.arr_dates;
}
void print_correct_dates(const char ** str, int count) {
    if (!str) {
        printf("NO CORRECT DATES\n");
        return;
    }

    printf("CORRECT DATES:\n");
    size_t i = 0;
    while (i < count && str[i]) {
        printf("%s\n", str[i]);
        i++;
    }
    printf("COUNT OF CORRECT DATES: %d\n", count);
}

char *enter_new_data (FILE *file, int check) {
    if (check == 1 && !file) return NULL;

    char *chunk = (char *) malloc(sizeof(char) * SIZE); // при больших строках size увеличится
    printf("malloc input_i (chunk)\n");

    if (!chunk)
        return NULL;

    if (check == 1) {
        if (fscanf(file, "%1024s", chunk) != 1) {
            free(chunk);
            return NULL;
        }
    } else {
        if (scanf("%1024s", chunk) != 1) {
            free(chunk);
            return NULL;
        }
    }

    return chunk;
}

// Фильтр СТРОК: Фильтр переданнного массива, который вводим или берем из файла в main
// (В цикле поочередно передаются все строки в функцию date_sym_filter)
int date_str_filter(const char **str, struct Dates *dates) {
    if (!str || !dates) return ERROR_STR_POINTER;

    for (size_t i = 0; str[i]; ++i) {
        if (date_sym_filter(str[i], dates) != WRONG_DATE_FORMAT) {
            dates->arr_dates[dates->el_count] = (char *) malloc (sizeof(char) * SIZE);
            if (!dates->arr_dates[dates->el_count])
                return MEMORY_ALLOCATION_ERROR;
            printf("malloc add_dates_i\n");
            strcpy(dates->arr_dates[dates->el_count], str[i]);
            printf("[%s]\n", dates->arr_dates[dates->el_count]);
            dates->el_count++;
         }
    }

    return dates->el_count;
}

// Фильтр посимвольный
int date_sym_filter(const char *str, struct Dates *dates) {
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
