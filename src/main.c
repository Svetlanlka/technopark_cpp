#include <stdlib.h>
#include <stdio.h>

#include "search_files.h"


int main(int argc, char *argv[]) {
    if (argc > 2) return INPUT_ERROR;

    const char* dir_name = NULL;
    if (argc == 2)
        dir_name = argv[1];

    printf("Ocheretnaya Svetlana. APO-13\n");

    if (read_directory(dir_name, 3) != 0) return PROGRAM_ERROR;
    

    return 0;
}
