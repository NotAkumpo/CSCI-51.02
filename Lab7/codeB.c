#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1e-16

int N;
long double X;
long double* sum;


long double factorial(int n){
    long double result = 1.0;
    for (int i=2; i<=n; i++){
        result *= i;
    }
    return result;
}

void* run_function( void* ptr ){
    int* i;
    i = (int *) ptr;
    int sign;
    int k = *i * 2 + 1;
    long double total = 0.0;

    if (*i % 2 == 0){
        sign = 1;
    }
    else {
        sign = -1;
    }

    while (true) {
        long double term = ( (powl(X, k)) / factorial(k) ) * sign;
        if (fabs(term) < MAX){
            break;
        }
        total += term;
        // printf("Thread %d: k = %d\n", *i, k);
        k = k + (N * 2);
        if (N % 2 == 1){
            sign = -sign;
        }
    }
    sum[*i] = total;
    return NULL;
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Error! Arguments are invalid!\n");
        abort();
    }

    N = atoi(argv[1]);
    X = strtold(argv[2], NULL);
    long double result = 0.0;
    sum = malloc(sizeof(long double) * N);

    if (N <= 0){
        printf("You need at least 1 thread!\n");
        abort();
    }

    pthread_t* threadArray = (pthread_t*) malloc(sizeof(pthread_t) * N);

    for (int i=0; i<N; i++){
        int* indexPointer = (int*) malloc(sizeof(int));
        *indexPointer = i;
        pthread_create(&threadArray[i], NULL, run_function, indexPointer);
    }

    for (int i=0; i<N; i++) {
        pthread_join(threadArray[i], NULL);
    }

    for (int i=0; i<N; i++){
        result += sum[i];
    }
    printf("The predicted series sum of the program is: %Lf\n", result);
    long double actualSum = sinl(X);
    printf("The actual sum of the series is: %Lf\n", actualSum);

    return 0;
}