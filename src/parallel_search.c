#include <search_files.h>
#include <my_library_search_files.h>

void * parallel_search_in_file (void * data);

struct Parallel_search_data {
    char ** arr_of_files;
    struct File_search * search_data;
    int part_number;
    int count_files;
};

void * parallel_search_in_file (void * data) {
    if (!data) return NULL;

    struct Parallel_search_data search_data = *(struct Parallel_search_data *) data;
    int * result = (int *) malloc (sizeof(int) * COUNT_CPU);
    if (!result) return NULL;

    for (int j = 0; j < search_data.count_files; ++j) {
        result[j] = search_in_file(search_data.arr_of_files[search_data.part_number + j], search_data.search_data);
    }

    pthread_exit ((void *) result);
}

struct File_info * parallel_sorting_files(char **arr_of_files, int * count_files, struct File_search * search_data) {
    if (!arr_of_files || !search_data || !count_files) return NULL;

    struct File_info * sorted_files = malloc(sizeof(struct File_info)* (*count_files));
    if (!sorted_files) return NULL;

    int thread_count = *count_files % COUNT_CPU == 0 ? *count_files / COUNT_CPU : *count_files / COUNT_CPU + 1;
    pthread_t thread[thread_count];
    struct Parallel_search_data data[thread_count];
    void *status[thread_count];
    int count_if_last_part = *count_files - (thread_count - 1) * COUNT_CPU;

    for (size_t i = 0; i < thread_count; ++i) {
        data[i].search_data = search_data;
        data[i].arr_of_files = arr_of_files;
        data[i].part_number = i;
        data[i].count_files = i == thread_count - 1 ? count_if_last_part : COUNT_CPU;

        if (pthread_create(&thread[i], NULL, parallel_search_in_file, &data[i]) != 0) {
            return NULL;
        }
    }

    for (size_t i = 0; i < thread_count; ++i) {
        if (pthread_join(thread[i], &status[i]) != 0) {
            return NULL;
        } else {
            int * new_count = (int*)status[i];
            int count_part = i == thread_count - 1 ? count_if_last_part : COUNT_CPU;

            // заполнение массива в отсортированном виде
            for (int j = 0; j < count_part; ++j) {
                insert_new_filepath(sorted_files, new_count[j], arr_of_files, i * COUNT_CPU + j);
            }
        }
    }

    for (int i = 0; i < thread_count; ++i) {
        free(status[i]);
    }

    return sorted_files;
}
