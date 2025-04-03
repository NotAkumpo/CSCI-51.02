#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* run_function( void* ptr ){
    int* i;
    i = (int *) ptr;
    int n = *i;
    if (*i % 2 == 0){
        *i = *i * *i * *i;
        printf("arr[%d](%d) has been replaced with arr[%d](%d)\n", n, n, n, *i);
    } else {
        *i = -*i;
        printf("arr[%d](%d) has been replaced with arr[%d](%d)\n", n, n, n, *i);
    }
    return NULL;
}

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("Error! No arguments provided!\n");
        abort();
    }

    int N = argc - 1;
    pthread_t* threadArray = (pthread_t*) malloc(sizeof(pthread_t) * N);
    int* arr = (int*) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        arr[i] = i;
        pthread_create(&threadArray[i], NULL, run_function, (arr + i));
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threadArray[i], NULL);
    }

    return 0;
}