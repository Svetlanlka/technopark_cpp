#include <stdlib.h>
#include <stdio.h>

#include "testy/date_parser.h"

/*Вариант #69
Составить программу построчной фильтрации текста, вводимого пользователем.
 Суть фильтра — отбор строк, содержащих запись времени как корректная последовательность «hh:mm:ss».
 Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 их количество и указатель на результирующую структуру.
 На выход функция должна возвращать количество строк в результирующей структуре.
 Результат обработки выводится на экран.*/

// Примечание: Формат *h:*m:*s не подходит, то есть кол-во hh, mm, ss обязательно должно быть 2

int main() {
    printf("Ocheretnaya Svetlana. APO-13\nINPUT_FILE: %s\n", INPUT_FILE);
    printf("Select input data:\nEnter 1, if from file \nEnter 2, if from keyboard\n");
    int check = 0;
    if (scanf("%d", &check) != 1) {
    	printf("input error\n");
    	return -1;
    }

    int count = 0;
    FILE *file;
    if (check == 1)
        file = fopen(INPUT_FILE, "r");

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
            if (fscanf(file, "%s", chunk) != 1) {
                free(chunk);
                if (LOG_MEMORY) printf("free chunk\n");
                break;
            }
        } else {
            if (scanf("%s", chunk) != 1 || chunk == NULL) {
                printf("%s", chunk);
                free(chunk);
                if (LOG_MEMORY) printf("free chunk\n");
                break;
            }
        }

        input_text[i] = chunk;
        i++;
    }

    count = Date_parser(input_text, i, &dates);

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
    printf("COUNT OF CORRECT DATE: %d\n", count);

    return 0;
}
