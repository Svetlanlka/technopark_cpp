#include <stdlib.h>
#include <stdio.h>

#include "date_parser.h"

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

    printf("COUNT OF CORRECT DATE: %d\n", Date_parser(INPUT_FILE, check));

    return 0;
}
