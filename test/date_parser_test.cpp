#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <string>

extern "C" {
    #include "testy/date_parser.h"
}

TEST(testy, not_ok) {
    ASSERT_EQ(0, 0);
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

// тест на основную функцию Date_parser с массивом строк (тестируется открытие файла и заполнение массива дат)
TEST(Date_parser, ok) {
    std::ifstream file;
    file.open("test0.txt");

    if (file.is_open()) std::cout << "success";
    else std::cout << "error of input file";

    ASSERT_TRUE(file.is_open());

    struct Dates dates = { NULL, 0, 0, 0 };
    char **input_text = new char *[SIZE];
    dates.arr_dates = new char *[SIZE];

    size_t i = 0;
    while(1) {
        char *chunk = new char [SIZE];

        file.getline(chunk, SIZE);
        std::cout <<  " chunk: " << chunk;

        for (size_t j = 0; chunk[j]; j++) {
            std::cout << chunk[j];
        }
        EXPECT_FALSE(chunk == nullptr);

        if (file.eof()) {
            break;
        }
        input_text[i] = chunk;
        i++;
    }

    std:: cout << "| " << i;
    for (size_t j = 0; j < i; j++) {
        std::cout << input_text[j] << " ";
    }

    std::cout << Date_parser(input_text, i, &dates);

    for (size_t j = 0; j < i; j++) {
        delete(input_text[j]);
    }
    delete input_text;

    for (size_t j = 0; j < dates.el_count; j++) {
        delete(dates.arr_dates[j]);
    }
    delete dates.arr_dates;
    file.close();
}

