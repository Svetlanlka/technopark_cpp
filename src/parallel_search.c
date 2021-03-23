//
// Created by svetlana on 23.03.2021.
//

#include "search_files.h"

struct Parallel_search_data {
    char ** arr_of_files;
    struct File_search * search_data;
    int part_number;
    int count_files;
};

struct Parallel_sorting_data {
    int new_count;
    int cur_number;
    char **arr_of_files;
    struct File_info * sorted_files;
};

void * parallel_search_in_file (void * data) {
    struct Parallel_search_data search_data = *(struct Parallel_search_data *) data;

    int * result = (int *) malloc (sizeof(int) * COUNT_CPU);
    for (int j = 0; j < search_data.count_files; ++j) {
        result[j] = search_in_file(search_data.arr_of_files[search_data.part_number + j], search_data.search_data);
    }

    if (PARALLEL_SEARCH_LOG)
        for (int j = 0; j < search_data.count_files; ++j) {
            printf("parallel search result: %d, flag: %d\n", result[j], search_data.part_number);
        }

//    for (int i = 0; i < 10; ++i) {
//        printf("THREAD #%d\n", search_data.flag);
//    }
    pthread_exit ((void *) result);
    // return ((void *) result);
}

struct File_info * parallel_sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data) {
    clock_t start = clock();

    if (SEARCH_LOG) printf("Parallel search and sorting files\n");
    struct File_info * sorted_files = malloc(sizeof(struct File_info)* (*count_files));

    int thread_count = *count_files % COUNT_CPU == 0 ? *count_files / COUNT_CPU : *count_files / COUNT_CPU + 1;
    pthread_t thread[thread_count];
    struct Parallel_search_data data[thread_count];
    // data = malloc ((sizeof(struct Parallel_search_data)));
    int result;
    void *status[thread_count];
    int count_if_last_part = *count_files - (thread_count - 1) * COUNT_CPU;

    clock_t end1 = clock();
    if (PARALLEL_SEARCH_LOG) printf("\nTIME: %ld\n%d\n", end1 - start, *count_files);
    for (size_t i = 0; i < thread_count; ++i) {
        data[i].search_data = search_data;
        data[i].arr_of_files = arr_of_files;
        data[i].part_number = i;
        data[i].count_files = i == thread_count - 1 ? count_if_last_part : COUNT_CPU;

        result = pthread_create(&thread[i], NULL, parallel_search_in_file, &data[i]);

        if (result != 0) {
            printf("Error with create thread\n");
            return NULL;
        }
        clock_t end2 = clock();
        printf("\nPthread arr TIME: %ld\ncount_files = %d, part_number = %d\n", end2 - start, data[i].count_files, data[i].part_number);

    }

    clock_t end5 = clock();

    printf("\npthread arr end TIME: %ld\n", end5 - start);
    for (size_t i = 0; i < thread_count; ++i) {
        if (PARALLEL_SEARCH_LOG) printf("JOIN #%zu\n", i);
        result = pthread_join(thread[i], &status[i]);


        if (result != 0) {
            printf("Error with join thread\n");
            return NULL;
        } else {
            if (PARALLEL_SEARCH_LOG)
                printf("\nSUCCESS PARALLEL SEARCH, result: %d\n", 1);//*((int*)status[i]));
        }

        int * new_count = (int*)status[i];
        // int new_count = search_in_file(arr_of_files[i], search_data);

        int count_part = i == thread_count - 1 ? count_if_last_part : COUNT_CPU;
        if (PARALLEL_SEARCH_LOG)
            for (int j = 0; j < count_part; ++j) {
                printf("\nSearch in file[%zu]: %s\nCOUNT: %d\n", i * COUNT_CPU + j, arr_of_files[i * COUNT_CPU + j], new_count[j]);
            }

        clock_t end3 = clock();
        printf("\nbefore sort TIME: %ld\n", end3 - start);
        // заполнение массива в отсортированном виде

        for (int j = 0; j < count_part; ++j) {
            insert_new_filepath(sorted_files, new_count[j], arr_of_files, i * COUNT_CPU + j);
        }
        clock_t end6 = clock();
        printf("\nafter sort TIME: %ld\n", end6 - start);
    }

    for (int i = 0; i < thread_count; ++i) {
        free(status[i]);
    }
    clock_t end4 = clock();
    printf("\nafter all TIME: %ld\n", end4 - start);

    return sorted_files;
}

