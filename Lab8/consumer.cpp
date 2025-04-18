#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <cstdio>
#include <cstring>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main( int argc, char* argv[] )
{
    if (argc != 3){
        printf("Error! Invalid Arguments!\n");
        abort();
    }

    ofstream outFile(argv[1]);
    int memorySize = atoi(argv[2]);

    key_t shmKey = 1234;
    int shmFlags = IPC_CREAT | 0666;

    int shmId = shmget( shmKey, memorySize, shmFlags ); 
    char* sharedMem = (char*)shmat( shmId, NULL, 0 );

    if( ((int*)sharedMem) == (int*)-1 )
    {
        perror( "shmop: shmat failed" );
        abort();
    }

    key_t shmKeyB = 4321;
    int shmFlagsB = IPC_CREAT | 0666;

    int shmIdB = shmget( shmKeyB, 2, shmFlagsB );
    char* sharedMemB = (char*)shmat( shmIdB, NULL, 0 );

    if( ((int*)sharedMemB) == (int*)-1 )
    {
        perror( "shmop: shmat failed" );
        abort();
    }

    key_t semKey = 1234;
    int semFlag = IPC_CREAT | 0666;
    int semId = semget( semKey, 1, semFlag );
    if( semId == -1 )
    {
        perror( "semget" );
        exit( 1 );
    }

    struct sembuf sema[1];

    sema[0].sem_num = 0;
    sema[0].sem_flg = SEM_UNDO;

    while (sharedMemB[0] != 9){
        cout << endl;
        sleep(1);
        cout << "Waiting for file semaphore to be available..." << endl;
        sema[0].sem_op = 0;
        semop( semId, sema, 1 );
        cout << "Claimed the file semaphore..." << endl;
        if (sharedMemB[0] == 1 ){
            sema[0].sem_op = 1;
            semop(semId, sema, 1);
            // sleep(4); // Only here to simulate the semaphore being held
            cout << "Writing to output file..." << endl;
            for (int i = 0; i < memorySize; i++){
                outFile.put(sharedMem[i]);
                cout << sharedMem[i];
            }
            cout << endl;
            sema[0].sem_op = -1;
            semop(semId, sema, 1);
            if (sharedMemB[0] != 9) {
                sharedMemB[0] = 2;
            }
        }
        else {
            cout << "Producer hasn't written a new batch, waiting..." << endl;
        }
    }
    cout << "Writing to output file..." << endl;
    for (int i = 0; i < memorySize; i++){
        if (sharedMem[i] == '\0'){
            break;
        }
        outFile.put(sharedMem[i]);
        cout << sharedMem[i];
    }

    shmdt(sharedMem);
    shmdt(sharedMemB);

    shmctl(shmId, IPC_RMID, NULL);
    shmctl(shmIdB, IPC_RMID, NULL);

    semctl(semId, 0, IPC_RMID);

    outFile.close();
    return 0;
}