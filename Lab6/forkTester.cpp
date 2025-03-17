#include <iostream>
#include <unistd.h> // some Unix stuff
using namespace std;


int main(void) {
    int id = getpid(); // or pid_t id = getpid();
    cout << "I am the parent process, my PID is " << id << endl;

    return 0;
}