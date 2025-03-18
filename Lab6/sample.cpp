#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Goodbye, World!" << endl;
    cout << "Process ID: " << getpid() << endl;

    // while (true) {
    //     sleep(1);  // Keep running so we can see it in `ps`
    // }

    return 0;
}