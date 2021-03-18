#include "gtest/gtest.h"
#include <string>

extern "C" {
    #include "date_filter.h"
}

// Тестирование основной функции (фильтра строк) - успешный результат, вывод какого-то количества верных дат
// **в файлах уже продуманы все исключения: (здесь также тестируются инскапсулированные функции библиотеки)
// не корректные символы, не верные числа в дате, неполный формат, много двоеточий, нехватка цифр
// при не верном формате даты, она просто не добавляется в итоговый массив строк
TEST(date_filter, ok) {
    int count = 0;
    char ** input_str = read_data_from_file("../unit_tests/test1.txt");
    char ** input_str3 = read_data_from_file("../unit_tests/test3.txt");
    char ** input_str4 = read_data_from_file("../unit_tests/test4.txt");
    char ** filter_str = date_filter((const char **) input_str, &count);
    EXPECT_EQ(count, 2);
    for (int i = 0; input_str[i]; i++) {
        free(input_str[i]);
    }
    free(input_str);
    for (int i = 0; i < count; i++) {
        free(filter_str[i]);
    }
    free(filter_str);

    char ** filter_str3 = date_filter((const char **) input_str3, &count);
    EXPECT_EQ(count, 21);
    for (int i = 0; input_str3[i]; i++) {
        free(input_str3[i]);
    }
    free(input_str3);
    for (int i = 0; i < count; i++) {
        free(filter_str3[i]);
    }
    free(filter_str3);

    char **filter_str4 = date_filter((const char **) input_str4, &count);
    EXPECT_EQ(count, 3);
    for (int i = 0; input_str4[i]; i++) {
        free(input_str4[i]);
    }
    free(input_str4);
    for (int i = 0; i < count; i++) {
        free(filter_str4[i]);
    }
    free(filter_str4);
}

// Передана NULL - строка
TEST(date_filter, str_is_null) {
    ASSERT_FALSE(date_filter(NULL, 0));
}

// Пустой файл, кол-во верных дат, соответсвенно, = 0
TEST(date_filter, no_correct_dates) {
    int count = 0;
    char **input_str = read_data_from_file("../unit_tests/test2.txt");
    char **filter_str = date_filter((const char **) input_str, &count);
    EXPECT_EQ(count, 0);
    for (int i = 0; input_str[i]; i++) {
        free(input_str[i]);
    }
    free(input_str);
    for (int i = 0; i < count; i++) {
        free(filter_str[i]);
    }
    free(filter_str);
}

// ok
TEST(read_data_from_file, ok) {
    char ** input_str = read_data_from_file("../unit_tests/test1.txt");
    EXPECT_TRUE(input_str);

    for (int i = 0; input_str[i]; i++) {
        free(input_str[i]);
    }
    free(input_str);
}

// файл не открылся
TEST(read_data_from_file, file_not_open) {
    char ** input_str = read_data_from_file("../unit_tests/wrong.txt");
    ASSERT_FALSE(input_str);
}

// имя файла - NULL
TEST(read_data_from_file, wrong_filename) {
    ASSERT_FALSE(read_data_from_file(NULL));
}

// верный вывод
TEST(print_correct_dates, ok) {
    char ** input_str = read_data_from_file("../unit_tests/test1.txt");
    EXPECT_EQ(print_correct_dates((const char **)input_str, SIZE), 0);

    for (int i = 0; input_str[i]; i++) {
        free(input_str[i]);
    }
    free(input_str);
}

// передано NULL
TEST(print_correct_dates, str_is_null) {
    ASSERT_EQ(print_correct_dates(NULL, 0), ERROR_STR_POINTER);
}
