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
    // std::cout << "TEST" << Date_parser("../test_file.txt", 1) << "\n";
    ASSERT_EQ(Date_parser("../test_cases/test1.txt", 1), 2);
    // std::fstream file("../test_cases/test1.txt", std::ios::in);

    // if (file.is_open()) std::cout << "SUCCESS!!!!\n";
    // else std::cout << "FILE NOT OPEN\n";
    // ASSERT_TRUE(false);
}
//    std::fstream file("test_cases/test1.txt", std::ios::in);
//
//    if (file.is_open()) std::cout << "SUCCESS!!!!\n";
//    else std::cout << "FILE NOT OPEN\n";
//
//    char c;
//    if (file.get(c))
//        std::cout << c;
//    std::cout << " Mda\n";
//    if (!file.eof()) std::cout << "success\n";
//    else std::cout << "not success\n";
//
//    ASSERT_TRUE(file.is_open());
//    ASSERT_FALSE(file.eof());
//    ASSERT_TRUE(file.good());
//
//    char ch;
//    file.get(ch);
//    std::cout << "(" << (int)ch << ")\n";
//    if (ch != EOF) std::cout << " CH != EOF\n";
//    else std::cout << "CH = EOF\n";
//    char ch2;
//    file.get(ch2);
//    std::cout << ch2;
//    std::string strr;
//    getline(file, strr);
//    std::cout << strr << " !";
//
//    struct Dates dates = { NULL, 0, 0, 0 };
//    char **input_text = new char *[SIZE];
//    dates.arr_dates = new char *[SIZE];
//
//    size_t i = 0;
//    while(true) {
//        char *chunk = new char [SIZE];
//
//        for (size_t j = 0; file.get(chunk[j]); ++j) {
//            std::cout << " [" << chunk[j] << "] ";
//            if (chunk[j] == '\n') break;
//        }
//
//        for (size_t j = 0; chunk[j] != '\0'; j++) {
//            std::cout << chunk[j];
//        }
//        EXPECT_FALSE(chunk == nullptr);
//
//        if (file.eof()) {
//            break;
//        }
//        input_text[i] = chunk;
//        i++;
//    }
//
//    std:: cout << "| " << i;
//    for (size_t j = 0; j < i; j++) {
//        std::cout << input_text[j] << " ";
//    }


//    for (size_t j = 0; j < i; j++) {
//        delete(input_text[j]);
//    }
//    delete input_text;
//
//    for (int j = 0; j < dates.el_count; j++) {
//        delete(dates.arr_dates[j]);
//    }
//    delete dates.arr_dates;
//    file.close();
//}

