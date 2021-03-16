#include "gtest/gtest.h"
#include <string>

extern "C" {
   #include "../src/date_parser.c"
   #include "date_parser.h"
}

// Тестирование функции Date_sym_parser, которая как раз содержит всю логику программы
// правильная работа программы
TEST(Date_sym_parser_success, ok) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "22:22:22";
    ASSERT_EQ(Date_sym_parser(str, &dates), 0);
}

// исключение, присуствуют не корректные символы
TEST(Date_sym_parser, not_sym) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "22:2-:s2";
    const char *str2 = "ssssssss";

    ASSERT_EQ(Date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
}

// исключение, не верные числа в дате
TEST(Date_sym_parser, wrong_number) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "25:33:33";
    const char *str2 = "22:60:50";
    const char *str3 = "22:50:60";
    ASSERT_EQ(Date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str3, &dates), WRONG_DATE_FORMAT);
}

// исключение, неполный формат даты
TEST(Date_sym_parser, wrong_format) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "::";
    const char *str2 = "1::0";
    const char *str3 = "0:0:0";
    ASSERT_EQ(Date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str3, &dates), WRONG_DATE_FORMAT);
}

// исключение, много двоеточий
TEST(Date_sym_parser, many_colon) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "13:22:11:22";
    const char *str2 = "::::";
    ASSERT_EQ(Date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
    ASSERT_EQ(Date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
}

// исключение, не хватает цифр
TEST(Date_sym_parser, no_number) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "11:11:";
    ASSERT_EQ(Date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
}

// Передана NULL строка
TEST(Date_sym_parser, null_str) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = NULL;
    ASSERT_EQ(Date_sym_parser(str, &dates), ERROR_STR_POINTER);
}

// Передана NULL структура
TEST(Date_sym_parser, null_structure) {
    struct Dates *dates = NULL;
    const char *str = "11:11:11";
    ASSERT_EQ(Date_sym_parser(str, dates), ERROR_STR_POINTER);
}

// передан NULL массив строк
TEST(Date_str_parser, null_str) {
    struct Dates dates = { NULL, 0, 0, 0 };
    char **str = NULL;
    ASSERT_EQ(Date_str_parser(str, SIZE, &dates), ERROR_STR_POINTER);
}

// тест на основную функцию Date_parser с массивом строк
 TEST(Date_parser, ok) {
    ASSERT_EQ(Date_parser("../unit_tests/test1.txt", 1), 2);
    ASSERT_EQ(Date_parser("../unit_tests/test2.txt", 1), 0);
    ASSERT_EQ(Date_parser("../unit_tests/test3.txt", 1), 21);
    ASSERT_EQ(Date_parser("../unit_tests/test4.txt", 1), 3);
}

TEST(Date_parser, file_not_open) {
    ASSERT_EQ(Date_parser("../unit_tests/test.txt", 1), ERROR_WITH_FILENAME);
}

// Передана NULL строка, как название файла
TEST(Date_parser, null_str) {
    ASSERT_EQ(Date_parser(NULL, 1), ERROR_WITH_FILENAME);
}

// передан NULL указатель
TEST(Enter_new_data, ok) {
    ASSERT_FALSE(Enter_new_data(NULL, 1));
}

