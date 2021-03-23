#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "unistd.h"

#include "search_files.h"

// Пример ввода: ./technopark_cpp "../testing_directory" cpp
// То есть: exe-шник директория запрос

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

int main(int argc, char *argv[]) {
    if (argc > 4) return INPUT_ERROR;

    // ввод запроса для поиска
    printf("Ocheretnaya Svetlana. APO-13\nEnter query to search: ");

    size_t i = 0;
    char *query = NULL;
    if (argc >= 3) {
        query = argv[2];
        i = strlen(argv[2]);
    } else {
        query = malloc(sizeof(char) * SIZE);
        while((query[i] = getchar()) != '\0' && query[i] != '\n') i++;
        query[i] = '\0';
    }

    struct File_search search_data  = {query, i};
    if (SEARCH_LOG) printf("query: %s, size of query: %zu\n", search_data.query, search_data.query_size);
    char **arr_of_files = malloc (sizeof(char *) * FILES_COUNT);
    int files_count = 0;

    if (read_directory(argv[1], arr_of_files, &files_count) != 0) return PROGRAM_ERROR;

    if (SEARCH_LOG) {
        for (size_t j = 0; j < files_count; j++)
            printf("file[%zu]: %s\n", j, arr_of_files[j]);
    }

    struct File_info *sorted_files = NULL;
    clock_t start = clock();
    if (argc == 4) {
        printf("PARALLEL SEARCH!\n");
         sorted_files = parallel_sorting_files(arr_of_files, &files_count, &search_data);
    } else {
        printf("USUAL SEARCH!\n");
        sorted_files = sorting_files(arr_of_files, &files_count, &search_data);
    }
    clock_t end = clock();
    printf("\nTIME: %ld\n", end - start);
    printf("\nTOP %d files:\n", TOP_SIZE);
    if (files_count) print_top_of_files(sorted_files, files_count < TOP_SIZE ? files_count : TOP_SIZE);



    // освобождение памяти
    for (size_t j = 0; j < files_count; ++j)
        free(arr_of_files[j]);
    free(arr_of_files);
    free(sorted_files);
    if (argc < 3) free(query);

   return 0;
}
