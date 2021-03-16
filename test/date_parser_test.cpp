#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <string>

extern "C" {
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
TEST(Date_sym_parser_fail, not_sym) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "22:2-:s2";
    const char *str2 = "ssssssss";

    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
}

// исключение, не верные числа в дате
TEST(Date_sym_parser_fail, wrong_number) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "25:33:33";
    const char *str2 = "22:60:50";
    const char *str3 = "22:50:60";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str3, &dates), -1);
}

// исключение, неполный формат даты
TEST(Date_sym_parser_fail, wrong_format) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "::";
    const char *str2 = "1::0";
    const char *str3 = "0:0:0";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str3, &dates), -1);
}

// исключение, много двоеточий
TEST(Date_sym_parser_fail, many_colon) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "13:22:11:22";
    const char *str2 = "::::";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
    ASSERT_EQ(Date_sym_parser(str2, &dates), -1);
}

// исключение, не хватает цифр
TEST(Date_sym_parser_fail, no_number) {
    struct Dates dates = { NULL, 0, 0, 0 };
    const char *str = "11:11:";
    ASSERT_EQ(Date_sym_parser(str, &dates), -1);
}

// тест на основную функцию Date_parser с массивом строк
 TEST(Date_parser, ok) {
    ASSERT_EQ(Date_parser("../unit_tests/test1.txt", 1), 2);
    ASSERT_EQ(Date_parser("../unit_tests/test2.txt", 1), 0);
    ASSERT_EQ(Date_parser("../unit_tests/test3.txt", 1), 21);
    ASSERT_EQ(Date_parser("../unit_tests/test4.txt", 1), 3);
}

TEST(Date_parser, file_not_open) {
    ASSERT_EQ(Date_parser("../unit_tests/test.txt", 1), -1);
}

//TEST(Enter_new_data, ok) {
//    FILE *file = fopen("../unit_tests/test1.txt", "r");
//    ASSERT_TRUE(Enter_new_data(file, 1));
//}
//
//TEST(Enter_new_data, not_ok) {
//    FILE *file = fopen("../unit_tests/test1.txt", "r");
//    ASSERT_EQ(Enter_new_data(file, 1), NULL);
//}
