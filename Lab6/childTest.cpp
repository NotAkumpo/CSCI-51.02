#include <iostream>
#include <unistd.h> // some Unix stuff
using namespace std;

int main(void){
    cout << "Hello" << endl;
    int i = 0;
    i += 2;
    pid_t child = fork();
    i += 3;
    cout << "i = " << i << endl;
    return 0;
}