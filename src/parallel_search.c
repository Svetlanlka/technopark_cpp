//
// Created by svetlana on 23.03.2021.
//

#include "search_files.h"

struct Parallel_search_data {
    const char * filepath;
    struct File_search * search_data;
    int flag;
};

struct Parallel_sorting_data {
    int new_count;
    int cur_number;
    char **arr_of_files;
    struct File_info * sorted_files;
};

void * parallel_search_in_file (void * data) {
    struct Parallel_search_data search_data = *(struct Parallel_search_data *) data;

    int * result = (int * ) malloc (sizeof(int));
    *result = search_in_file(search_data.filepath, search_data.search_data);

    if (PARALLEL_SEARCH_LOG)
        printf("parallel search result: %d, flag: %d\n", *result, search_data.flag);
//    for (int i = 0; i < 10; ++i) {
//        printf("THREAD #%d\n", search_data.flag);
//    }
    pthread_exit ((void *) result);
    // return ((void *) result);
}

/*struct SSum {
    int a;
    int b;
};

int sum(int a, int b) {
    return a + b;
}

void * to_sum (void * s) {
    struct SSum ss = *(struct SSum *) s;

    int * res = (int *) malloc (sizeof(int));
    *res = sum(ss.a, ss.b);
    printf("ARGS: %d, %d\n", ss.a, ss.b);
    printf("SUM: %d\n", *res);
    // pthread_exit((res));
    for (int j = 0; j < 5; j++) {
        printf("THREAD #%d\n", ss.b);
        sleep(1);
    }
    pthread_exit ((void *) res);
}
*/
/*
int main(int argc, char *argv[]) {
    int N = 4;
    int result;
    pthread_t thread[N];
    struct SSum ss[N];
    void *status[N];
    //ss = malloc( (sizeof(struct SSum)));
    //ss->b = 2;
    //ss->a = 1;
    for (int i = 0; i < N; ++i) {
        ss[i].a = i * 10;
        ss[i].b = i;
        result = pthread_create(&thread[i], NULL, to_sum, &ss[i]);
        if (!result) {
            printf("Success: %d, %d\n", result, i);
        }
    }

    for (int i = 0; i < N; ++i) {
        result = pthread_join(thread[i], &status[i]);
        if (result != 0) {
            printf("Error!\n");
        } else {
            //struct SSum st = *(struct SSum *) status;
            printf("RESULTS: %d", *((int *) status));
        }
    }

    return 0;
}*/

/*struct File_info * sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data) {
    if (SEARCH_LOG) printf("Ordinary search and sorting files\n");
    struct File_info * sorted_files = malloc(sizeof(struct File_info)* (*count_files));

    for (size_t i = 0; i < *count_files; ++i) {
        int new_count = search_in_file(arr_of_files[i], search_data);
        if (SEARCH_LOG)
            printf("\nSearch in file[%zu]: %s\nCOUNT: %d\n", i, arr_of_files[i], new_count);

        // заполнение массива в отсортированном виде
        insert_new_filepath(sorted_files, new_count, arr_of_files, i);
    }

    return sorted_files;
}*/

struct File_info * parallel_sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data) {
    if (SEARCH_LOG) printf("Parallel search and sorting files\n");
    struct File_info * sorted_files = malloc(sizeof(struct File_info)* (*count_files));
    pthread_t thread[*count_files];
    struct Parallel_search_data data[*count_files];
    // data = malloc ((sizeof(struct Parallel_search_data)));
    int result;
    void *status[*count_files];

    for (size_t i = 0; i < *count_files; ++i) {
        data[i].search_data = search_data;
        data[i].filepath = arr_of_files[i];
        data[i].flag = i;
        result = pthread_create(&thread[i], NULL, parallel_search_in_file, &data[i]);

        if (result != 0) {
            printf("Error with create thread\n");
            return NULL;
        }
    }

    for (size_t i = 0; i < *count_files; ++i) {
        result = pthread_join(thread[i], &status[i]);
        if (result != 0) {
            printf("Error with join thread\n");
            return NULL;
        } else {
            if (PARALLEL_SEARCH_LOG)
                printf("\nSUCCESS PARALLEL SEARCH, result: %d\n", *((int*)status[i]));
        }

        int new_count = *((int*)status[i]);
        // int new_count = search_in_file(arr_of_files[i], search_data);
        if (PARALLEL_SEARCH_LOG)
            printf("\nSearch in file[%zu]: %s\nCOUNT: %d\n", i, arr_of_files[i], new_count);

        // заполнение массива в отсортированном виде
        insert_new_filepath(sorted_files, new_count, arr_of_files, i);
    }

    for (int i = 0; i < *count_files; ++i) {
        free(status[i]);
    }

    return sorted_files;
}

