#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int* arr;

void* run_function( void *ptr )
{
    int* i;
    i = (int *) ptr;
    if (*i % 2 == 0){
        arr[*i] = *i * *i * *i;
        printf("arr[%d](%d) has been replaced with arr[%d](%d)\n", *i, *i, *i, arr[*i]);
    } else {
        arr[*i] = -*i;
        printf("arr[%d](%d) has been replaced with arr[%d](%d)\n", *i, *i, *i, arr[*i]);
    }
    free(ptr);
    return NULL;
}

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Error! No arguments provided!\n");
        abort();
    }

    int N = argc - 1;
    pthread_t* threadArray = (pthread_t*) malloc(sizeof(pthread_t) * N);
    arr = (int*) malloc(sizeof(int) * N);
    int* indices = (int*) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        arr[i] = i;
        int* indexPointer = (int*) malloc(sizeof(int));
        *indexPointer = i;
        pthread_create(&threadArray[i], NULL, run_function, indexPointer);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threadArray[i], NULL);
    }

    return 0;
}