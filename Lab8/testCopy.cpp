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

    char ch;
    while (true){
        if (inFile.get(ch)){
            outFile.put(ch);
        } else {
            break;
        }
    }

    inFile.close();
    outFile.close();

    return 0;
}