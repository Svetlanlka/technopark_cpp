#include "gtest/gtest.h"
#include <string.h>
#include <pthread.h>

extern "C" {
    #include "search_files.h"
    #include "my_library_search_files.h"
}

TEST(sorting_files, ok) {
    const char *query = "cpp";
    file_search search_data  = {(char *)query, 3};
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;

    read_directory("../testing_directory3", arr_of_files, &files_count);
    file_info * sorted_files = parallel_sorting_files(arr_of_files, &files_count, &search_data);

    EXPECT_STREQ(sorted_files[0].filepath, "../testing_directory3/bfile.txt");
    EXPECT_EQ(sorted_files[0].count, 100);
    EXPECT_STREQ(sorted_files[1].filepath, "../testing_directory3/ifile.txt");
    EXPECT_EQ(sorted_files[1].count,  98);
    EXPECT_STREQ(sorted_files[2].filepath, "../testing_directory3/jfile.txt");
    EXPECT_EQ(sorted_files[2].count, 92);
    EXPECT_STREQ(sorted_files[3].filepath, "../testing_directory3/afile.txt");
    EXPECT_EQ(sorted_files[3].count, 12);
    EXPECT_STREQ(sorted_files[4].filepath, "../testing_directory3/dfile.txt");
    EXPECT_EQ(sorted_files[4].count, 2);

    free_arr(arr_of_files, files_count);
    free(sorted_files);
    delete [] arr_of_files;
}

TEST(sorting_files, null_arr_ptr) {
    char **arr_of_files = NULL;
    int files_count = 0;
    const char *query = "word";
    file_search search_data  = {(char *)query, 4};
    EXPECT_FALSE(sorting_files(arr_of_files, &files_count, &search_data));
    ASSERT_FALSE(parallel_sorting_files(arr_of_files, &files_count, &search_data));
}

TEST(sorting_files, null_count_ptr) {
    char **arr_of_files = new char * [FILES_COUNT];
    const char *query = "word";
    file_search search_data  = {(char *)query, 4};
    file_info *sorted_files = sorting_files(arr_of_files, NULL, &search_data);
    EXPECT_FALSE(sorted_files);
    ASSERT_FALSE(parallel_sorting_files(arr_of_files, NULL, &search_data));

    delete [] arr_of_files;
}

TEST(sorting_files, null_search_ptr) {
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;
    file_info *sorted_files = sorting_files(arr_of_files, &files_count, NULL);
    EXPECT_FALSE(sorted_files);
    ASSERT_FALSE(parallel_sorting_files(arr_of_files, &files_count, NULL));

    free_arr(arr_of_files, files_count);
    free(sorted_files);
    delete [] arr_of_files;
}


TEST(sorting_files, file_not_open) {
    const char *query = "cpp";
    file_search search_data  = {(char *)query, 3};
    int files_count = 2;
    char **arr_of_files = new char * [files_count];

    arr_of_files[0] = new char[SIZE];
    arr_of_files[1] = new char[SIZE];
    strcpy(arr_of_files[0], "../testing_directory3/afile.txt");
    strcpy(arr_of_files[1], "../testing_directory3/wrong.txt");

    file_info *sorted_files = sorting_files(arr_of_files, &files_count, &search_data);
    ASSERT_FALSE(sorted_files);

    delete [] arr_of_files[0];
    delete [] arr_of_files[1];
    delete [] arr_of_files;
}

TEST(read_directory, ok) {
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;
    read_directory("../testing_directory", arr_of_files, &files_count);

    int i = 0;
    for (; i < files_count; ++i) {
        if (strcmp(arr_of_files[i], "../testing_directory/test3.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/test1.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/test4.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir1/dir1_1/dir1_1_1/test1_1_1_1.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir1/dir1_1/test1_1_1.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir1/dir1_1/test1_1_1 (копия).txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir1/test1_1.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir2/test2_2.txt") &&
            strcmp(arr_of_files[i], "../testing_directory/dir1/test1_3.txt")) break;
    }

    ASSERT_EQ(i, files_count);

    free_arr(arr_of_files, files_count);
    delete [] arr_of_files;
}

TEST(read_directory, not_open_dir) {
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;
    ASSERT_EQ(read_directory("../wrong", arr_of_files, &files_count), OPEN_FILE_ERROR);

    free_arr(arr_of_files, files_count);
    delete [] arr_of_files;
}

TEST(read_directory, null_arr) {
    int files_count = 0;
    ASSERT_EQ(read_directory("../testing_directory", NULL, &files_count), NULL_POINTER_ERROR);
}

TEST(read_directory, null_name_dir) {
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;
    ASSERT_EQ(read_directory(NULL, arr_of_files, &files_count), NULL_POINTER_ERROR);

    free_arr(arr_of_files, files_count);
    delete [] arr_of_files;
}

TEST(read_directory, null_count) {
    char **arr_of_files = new char * [FILES_COUNT];
    ASSERT_EQ(read_directory(NULL, arr_of_files, NULL), NULL_POINTER_ERROR);

    delete [] arr_of_files;
}

TEST(print_top_of_files, ok) {
    const char *query = "cpp";
    file_search search_data  = {(char *)query, 3};
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;
    read_directory("../testing_directory", arr_of_files, &files_count);
    file_info *sorted_files = sorting_files(arr_of_files, &files_count, &search_data);
    ASSERT_EQ(print_top_of_files(sorted_files, TOP_SIZE), 0);

    free_arr(arr_of_files, files_count);
    free(sorted_files);
    delete [] arr_of_files;
}

TEST(print_top_of_files, null_ptr) {
    ASSERT_EQ(print_top_of_files(NULL, TOP_SIZE), NULL_POINTER_ERROR);
}

TEST(parallel_sorting_files, ok) {
    const char *query = "cpp";
    file_search search_data  = {(char *)query, 3};
    char **arr_of_files = new char * [FILES_COUNT];
    int files_count = 0;

    read_directory("../testing_directory3", arr_of_files, &files_count);
    file_info *sorted_files = parallel_sorting_files(arr_of_files, &files_count, &search_data);

    EXPECT_STREQ(sorted_files[0].filepath, "../testing_directory3/bfile.txt");
    EXPECT_EQ(sorted_files[0].count, 100);
    EXPECT_STREQ(sorted_files[1].filepath, "../testing_directory3/ifile.txt");
    EXPECT_EQ(sorted_files[1].count,  98);
    EXPECT_STREQ(sorted_files[2].filepath, "../testing_directory3/jfile.txt");
    EXPECT_EQ(sorted_files[2].count, 92);

    free_arr(arr_of_files, files_count);
    free(sorted_files);
    delete [] arr_of_files;
}

// file_info * sorting_files(char **arr_of_files, int * count_files, file_search * search_data)
