#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <cstdio>
#include <cstdlib>

using namespace std;

int main( int argc, char* argv[] )
{

        // -- Semaphore Initialization --

    // Semaphore set ID
    int semId;

    // 1 key = 1 semaphore set (or array)
    // Think of it like a map (the data structure)
    // Put a large constant here, e.g. 1234
    key_t semKey = 9999;

    // Flags to use upon getting the semaphore set.
    // Normally when dealing with flags, you usually bitwise-OR
    // flags together.
    // IPC_CREAT - If no existing semaphore set is associated with the key, create one
    // 0666 - Remember chmod? The 0 in front specifies that the number is in octal
    int semFlag = IPC_CREAT | 0666;

    // Number of semaphores in the semaphore set
    // For this example, we'll just create 1 semaphore set
    int nSems = 1;

    // Attempt to get a semaphore set
    // Returns -1 if there was an error.
    semId = semget( semKey, nSems, semFlag );
    if( semId == -1 )
    {
        perror( "semget" );
        exit( 1 );
    }

    printf( "semId = %d\n", semId );

    // int setResult = semctl(semId, 0, SETVAL, 0);
    // if (setResult == -1) {
    //     perror("semctl SETVAL");
    // } else {
    //     printf("Semaphore reset to 0\n");
    // }


    int semVal = semctl(semId, 0, GETVAL);
    if (semVal == -1) {
        perror("semctl GETVAL");
    } else {
        printf("Current semaphore value: %d\n", semVal);
    }

    // -- Semaphore Accessing --

    // Perform 2 operations
    int nOperations = 1;

    // Create an array of size 2 to hold
    // the operations that we will do on the semaphore set
    struct sembuf sema[nOperations];

    // Definition for the first operation
    // Our first operation will be to wait for the
    // semaphore to become 0
    sema[0].sem_num = 0; // Use the first semaphore in the semaphore set
    sema[0].sem_op = -1; // Increment semaphore by 1 
    sema[0].sem_flg = SEM_UNDO; // See slides

    // sema[1].sem_num = 0; // Use the first semaphore in the semaphore set
    // sema[1].sem_op = 1; // Wait if semaphore != 0
    // sema[1].sem_flg = SEM_UNDO; // See slides

    int opResult = semop( semId, sema, nOperations );

    printf( "opResult = %d\n", opResult );

    semVal = semctl(semId, 0, GETVAL);
    if (semVal == -1) {
        perror("semctl GETVAL");
    } else {
        printf("Current semaphore value: %d\n", semVal);
    }

    return 0;
}