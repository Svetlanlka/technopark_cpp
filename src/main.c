#include <stdlib.h>
#include <stdio.h>

#include "date_filter.h"

/*Вариант #69
Составить программу построчной фильтрации текста, вводимого пользователем.
 Суть фильтра — отбор строк, содержащих запись времени как корректная последовательность «hh:mm:ss».
 Фильтр должен быть реализован как функция, принимающая на вход указатель на вектор строк,
 их количество и указатель на результирующую структуру.
 На выход функция должна возвращать количество строк в результирующей структуре.
 Результат обработки выводится на экран.*/

// Примечание: Формат *h:*m:*s не подходит, то есть кол-во hh, mm, ss обязательно должно быть 2

int main(int argc, char *argv[]) {
    if (argc > 2) return INPUT_ERROR;

    const char* filename = NULL;
    if (argc == 2)
        filename = argv[1];

    printf("Ocheretnaya Svetlana. APO-13\n");
    int count = 0;
    char ** input_str = NULL;
    input_str = argc == 2 ? read_data_from_file(filename) : input_data();
    char ** filter_str = date_filter((const char **) input_str, &count);
    print_correct_dates((const char **) filter_str, count);

    // чистка памяти
    for (size_t i = 0; input_str[i]; i++) {
      free(input_str[i]);
    }
    free(input_str);

    for (int i = 0; i < count; i++) {
      free(filter_str[i]);
    }
    free(filter_str);

    return 0;
}
