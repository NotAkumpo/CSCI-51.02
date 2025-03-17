#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Process ID: " << getpid() << endl;

    cout << "sampleinputtext\n";
    int i = 0;
    i += 2;
    int n = fork();
    i += 3;
    cout << i << endl;

    if (n == 0){
        cout << "Child process\n";
        cout << "Process ID: " << getpid() << endl;
    } else {
        cout << "Parent process\n";
        cout << "Process ID: " << getpid() << endl;
    }

    return 0;
}