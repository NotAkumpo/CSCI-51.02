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

using namespace std;

int main( int argc, char* argv[] )
{
    if (argc != 3){
        printf("Error! Invalid Arguments!\n");
        abort();
    }

    ifstream inFile(argv[1]);
    ofstream outFile("textfileCopy.txt");

    key_t shmKey = 1234;
    int shmFlags = IPC_CREAT | 0666;

    int shmId = shmget( shmKey, 16, shmFlags ); 
    char* sharedMem = (char*)shmat( shmId, NULL, 0 );
    char* origSharedMem = sharedMem;

    char ch;
    // while (inFile.get(ch)){
    //     memset(sharedMem, 0, 16);
    //     *sharedMem = ch;
    //     sharedMem++;
    //     cout << ch;
    //     sharedMem = origSharedMem;
    // }

    memset(sharedMem, 0, 16);
    for (int i = 0; i < 16; i++){
        inFile.get(ch);
        sharedMem[i] = ch;
        cout << ch;
    }

    for (int i = 0; i < 16; i++){
        outFile.put(sharedMem[i]);
        cout << sharedMem[i];
    }

    inFile.close();
    outFile.close();

    return 0;
}