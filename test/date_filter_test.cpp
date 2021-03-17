#include "gtest/gtest.h"
#include <string>

extern "C" {
    #include "date_filter.h"
}

// Тестирование основной функции (фильтра строк) - успешный результат
TEST(date_filter, ok) {
    int count = 0;
    char ** input_str = read_data_from_file("../unit_tests/test1.txt");
    date_filter((const char **) input_str, &count);
    EXPECT_EQ(count, 2);

//    int count2 = 0;
//    char ** input_str2 = read_data_from_file("../unit_tests/test2.txt");
// char ** input_str3 = read_data_from_file("../unit_tests/test3.txt");
// char ** input_str4 = read_data_from_file("../unit_tests/test4.txt");
//    date_filter((const char **) input_str2, &count2);
//    EXPECT_EQ(count2, 0);
//    count = 0;
//    date_filter((const char **) input_str3, &count);
//    EXPECT_EQ(count, 21);
//    count = 0;
//    date_filter((const char **) input_str4, &count);
//    ASSERT_EQ(count, 3);

}

// ok
TEST(read_data_from_file, ok) {
    ASSERT_TRUE(read_data_from_file("../unit_tests/test1.txt"));
}

// файл не открылся
TEST(read_data_from_file, file_not_open) {
    ASSERT_FALSE(read_data_from_file("../unit_tests/wrong.txt"));
}

// имя файла - NULL
TEST(read_data_from_file, wrong_filename) {
    ASSERT_FALSE(read_data_from_file(nullptr));
}

TEST(print_correct_dates, wrong_filename) {
    ASSERT_FALSE(read_data_from_file(nullptr));
}

//// Тестирование функции Date_sym_parser, которая как раз содержит всю логику программы
//// правильная работа программы
//TEST(date_sym_parser_success, ok) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "22:22:22";
//    ASSERT_EQ(date_sym_parser(str, &dates), 0);
//}
//
//// исключение, присуствуют не корректные символы
//TEST(date_sym_parser, not_sym) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "22:2-:s2";
//    const char *str2 = "ssssssss";
//
//    ASSERT_EQ(date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
//}
//
//// исключение, не верные числа в дате
//TEST(Date_sym_parser, wrong_number) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "25:33:33";
//    const char *str2 = "22:60:50";
//    const char *str3 = "22:50:60";
//    ASSERT_EQ(date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str3, &dates), WRONG_DATE_FORMAT);
//}
//
//// исключение, неполный формат даты
//TEST(date_sym_parser, wrong_format) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "::";
//    const char *str2 = "1::0";
//    const char *str3 = "0:0:0";
//    ASSERT_EQ(date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str3, &dates), WRONG_DATE_FORMAT);
//}
//
//// исключение, много двоеточий
//TEST(Date_sym_parser, many_colon) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "13:22:11:22";
//    const char *str2 = "::::";
//    ASSERT_EQ(date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
//    ASSERT_EQ(date_sym_parser(str2, &dates), WRONG_DATE_FORMAT);
//}
//
//// исключение, не хватает цифр
//TEST(date_sym_parser, no_number) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = "11:11:";
//    ASSERT_EQ(date_sym_parser(str, &dates), WRONG_DATE_FORMAT);
//}
//
//// Передана NULL строка
//TEST(date_sym_parser, null_str) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    const char *str = NULL;
//    ASSERT_EQ(date_sym_parser(str, &dates), ERROR_STR_POINTER);
//}
//
//// Передана NULL структура
//TEST(date_sym_parser, null_structure) {
//    struct Dates *dates = NULL;
//    const char *str = "11:11:11";
//    ASSERT_EQ(date_sym_parser(str, dates), ERROR_STR_POINTER);
//}
//
//// передан NULL массив строк
//TEST(Date_str_parser, null_str) {
//    struct Dates dates = { NULL, 0, 0, 0 };
//    char **str = NULL;
//    ASSERT_EQ(date_str_parser(str, SIZE, &dates), ERROR_STR_POINTER);
//}

// тест на основную функцию date_filter с массивом строк
// TEST(date_filter, ok) {
//
//    ASSERT_EQ(date_filter("../unit_tests/test1.txt", 1), 2);
//    ASSERT_EQ(date_filter("../unit_tests/test2.txt", 1), 0);
//    ASSERT_EQ(date_filter("../unit_tests/test3.txt", 1), 21);
//    ASSERT_EQ(date_filter("../unit_tests/test4.txt", 1), 3);
//}

//TEST(date_filter, file_not_open) {
//    ASSERT_EQ(date_filter("../unit_tests/test.txt", 1), ERROR_WITH_FILENAME);
//}
//
//// Передана NULL строка, как название файла
//TEST(date_filter, null_str) {
//    ASSERT_EQ(date_filter(NULL, 1), ERROR_WITH_FILENAME);
//}

//// передан NULL указатель
//TEST(enter_new_data, ok) {
//    ASSERT_FALSE(enter_new_data(NULL, 1));
//}

//char** date_filter(const char **str);
//void print_correct_dates(const char **str);
//char** input_data();
//char** read_data_from_file(const char *filename);