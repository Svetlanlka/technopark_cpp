#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <string>

extern "C" {
    #include "testy/date_parser.h"
}

// Тестирование функции Date_sym_parser, которая как раз содержит всю логику программы
// правильная работа программы
TEST(Date_sym_parser, ok) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "22:22:22";
    ASSERT_EQ(Date_sym_parser(str, &dates), 0);
}

// исключение, присуствуют не корректные символы
TEST(Date_sym_parser_not_sym, not_ok) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "22:2-:s2";
    const char *str2 = "ssssssss";

    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
}

// исключение, не верные числа в дате
TEST(Date_sym_parser_wrong_number, not_ok) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "25:33:33";
    const char *str2 = "22:60:50";
    const char *str3 = "22:50:60";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str3, &dates), -1);
}

// исключение, неполный формат даты
TEST(Date_sym_parser_wrong_format, not_ok) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "::";
    const char *str2 = "1::0";
    const char *str3 = "0:0:0";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str3, &dates), -1);
}

// тест на основную функцию Date_parser с массивом строк
 TEST(Date_parser, ok) {
    ASSERT_EQ(Date_parser("../test_cases/test1.txt", 1), 2);
}

