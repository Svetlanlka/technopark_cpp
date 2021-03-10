#include <stdlib.h>
#include <stdio.h>

#include "date_parser.h"

// Парсинг переданнного массива, который вводим или берем из файла в main
int Date_parser(char **str, size_t size, struct Dates *dates) {
    int count = 0;
    for (size_t i = 0; i < size && str[i]; ++i) {
        if (PARSER_LOG) printf("Check str: %s\n", str[i]);

        char *date_str = (char *) malloc (sizeof(char) * SIZE * (size / SIZE + 1));
        if (LOG_MEMORY) printf("malloc date_str (to arr_dates)\n");

        if (Date_sym_parser(str[i], dates, date_str) != -1) {
            if (PARSER_LOG) printf("\nADD\n");
            dates->arr_dates[dates->el_count++] = date_str;
        } else {
            free(date_str);
            if (LOG_MEMORY) printf("free date_str_i\n");
            if (PARSER_LOG) printf("\nNOT ADD\n");
        }
    }

    return dates->el_count;
}

// Парсинг отдельно каждой строки
int Date_sym_parser(char *str, struct Dates *dates, char *result_str) {
    int cur_num = 0; // текущее значение (час 0-23/минута 0-59/секунда 0-59)
    dates->colon_count = 0;
    dates->count_sym = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if ((int)str[i] >= 48 && (int)str[i] <= 57) {
            if (PARSER_LOG) printf("correct sym %c | ", str[i]);

            cur_num = cur_num * 10 + ((int)str[i] - 48);
            if (PARSER_LOG) printf("current num: %d\n", cur_num);

            if (++dates->count_sym > 2)
                return -1;
            if ((dates->colon_count == 0 && cur_num > 23) || (dates->colon_count != 0 && cur_num > 59))
                return -1;
        } else if ((int)str[i] == 58) {
            if (PARSER_LOG) printf("colon sym: %c\n", str[i]);
            cur_num = 0;
            if (dates->count_sym != 2)
                return -1;
            dates->count_sym = 0;
            if (++dates->colon_count > 2)
                return -1;
        } else {
            if (PARSER_LOG) printf("error type of sym\n");
            return -1;
        }
    }

    if (dates->colon_count != 2)
        return -1;
    return 0;
}
