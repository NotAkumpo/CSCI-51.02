#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Hello, World!" << endl;
    cout << "Process ID: " << getpid() << endl;

    // execv("sample", argv);

    if (execv("sample", argv) == -1){
        cout << "Error: execv failed" << endl;
    }
    cout << "Will this line be printed?" << endl;

    // if (execl("sample", "REALLY NOT GEDIT", NULL) == -1){
    //     cout << "Error: execv failed" << endl;
    // }
    // cout << "Will this line be printed?" << endl;

    return 0;
}