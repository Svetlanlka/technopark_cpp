#include <stdlib.h>
#include <stdio.h>

#include "date_parser.h"

int Date_parser(const char *filename, int check) {
    FILE *file = NULL;
    if (check == 1)
        file = fopen(filename, "r");
    if (!file) return -1;

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

    for (size_t j = 0; j < dates.el_count; j++) {
        free(dates.arr_dates[j]);
    }
    free(dates.arr_dates);
    if (check == 1) fclose(file);

    return count;
}

char *Enter_new_data (FILE *file, int check) {
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
    for (size_t i = 0; i < size && str[i]; ++i) {
        char *date_str = (char *) malloc (sizeof(char) * SIZE * (size / SIZE + 1));

        if (Date_sym_parser(str[i], dates) != -1) {
            dates->arr_dates[dates->el_count++] = date_str;
        } else {
            free(date_str);
        }
    }

    return dates->el_count;
}

// Парсинг посимвольный
int Date_sym_parser(const char *str, struct Dates *dates) {
    int cur_num = 0; // текущее значение (час 0-23/минута 0-59/секунда 0-59)
    dates->colon_count = 0;
    dates->count_sym = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && (int)str[i] <= '9') {
            cur_num = cur_num * 10 + (str[i] - '0');

            if (++dates->count_sym > 2)
                return -1;
            if ((dates->colon_count == 0 && cur_num > LIMIT_HOURS_OF_DAY) || (dates->colon_count != 0 && cur_num > TIME_LIMIT))
                return -1;
        } else if (str[i] == ':') {
            cur_num = 0;
            if (dates->count_sym != 2)
                return -1;
            dates->count_sym = 0;
            if (++dates->colon_count > 2)
                return -1;
        } else {
            return -1;
        }
    }

    if (dates->colon_count != 2)
        return -1;
    if (dates->count_sym == 0)
        return -1;
    return 0;
}
