#include "gtest/gtest.h"

extern "C" {
    #include "date_parser.h"
}

TEST(Date_parser, ok) {
    FILE *file = fopen("../test_cases/test1.txt", "r");
    struct Dates dates = { NULL, 0, 0, 0 };
    char **input_text = (char **) malloc(sizeof(char*) * SIZE);
    dates.arr_dates = (char **) malloc(sizeof(char*) * SIZE);

    size_t i = 0;
    while(1) {
        char *chunk = (char *) malloc(sizeof(char) * SIZE);
        if (fscanf(file, "%s", chunk) != 1) {
            free(chunk);
            break;
        }
        input_text[i] = chunk;
        i++;
    }

    ASSERT_EQ(Date_parser(input_text, i, &dates), 2);
}