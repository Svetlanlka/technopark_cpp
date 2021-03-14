#include <stdlib.h>
#include <stdio.h>

#include "testy/date_parser.h"


int Date_parser(const char *filename, int check) {
    FILE *file = NULL;
    if (check == 1)
        file = fopen(filename, "r");

    struct Dates dates = { NULL, 0, 0, 0 };

    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    if (LOG_MEMORY) printf("malloc input_text\n");
    dates.arr_dates = (char **) malloc(sizeof(char*) * SIZE);
    if (LOG_MEMORY) printf("malloc arr_dates\n");

    // ввод данных
    size_t i = 0;
    while(1) {
        char *chunk = (char *) malloc(sizeof(char) * SIZE); // при больших строках size увеличится
        if (LOG_MEMORY) printf("malloc chunk\n");
        if (check == 1) {
            if (fscanf(file, "%1024s", chunk) != 1) {
                free(chunk);
                if (LOG_MEMORY) printf("free chunk\n");
                break;
            }
        } else {
            if (scanf("%1024s", chunk) != 1) {
                if (!chunk)
                    break;
                printf("%s", chunk);
                free(chunk);
                if (LOG_MEMORY) printf("free chunk\n");
                break;
            }
        }

        input_text[i] = chunk;
        i++;
    }

    int count = Date_str_parser(input_text, i, &dates);

    // чистка памяти
    for (size_t j = 0; j < i; j++) {
        free(input_text[j]);
        if (LOG_MEMORY) printf("free input_text_i (chunk) \n");
    }
    free(input_text);
    if (LOG_MEMORY) printf("free input_text\n");

    for (size_t j = 0; j < dates.el_count; j++) {
        free(dates.arr_dates[j]);
        if (LOG_MEMORY) printf("free arr_dates_i\n");
    }
    free(dates.arr_dates);
    if (LOG_MEMORY) printf("free arr_dates\n");

    if (check == 1) fclose(file);

    return count;
}

// ПАРСИНГ СТРОК: Парсинг переданнного массива, который вводим или берем из файла в main
// (В цикле поочередно передаются все строки в функцию Date_sym_parser)
int Date_str_parser(char **str, size_t size, struct Dates *dates) {
    for (size_t i = 0; i < size && str[i]; ++i) {
        if (PARSER_LOG) printf("Check str: %s\n", str[i]);

        char *date_str = (char *) malloc (sizeof(char) * SIZE * (size / SIZE + 1));
        if (LOG_MEMORY) printf("malloc date_str (to arr_dates)\n");

        if (Date_sym_parser(str[i], dates) != -1) {
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

// Парсинг посимвольный
int Date_sym_parser(const char *str, struct Dates *dates) {
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
    if (dates->count_sym == 0)
        return -1;
    return 0;
}
