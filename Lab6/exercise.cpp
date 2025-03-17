#include <iostream>
#include <unistd.h> // some Unix stuff
using namespace std;

int main(int argc, char *argv[]){
    int var = 4;
    var += 2;

    if (fork() == 0){
        var += 8;
        cout << "Child ID: " << getpid() << endl;
        cout << "Child: var = " << var << endl;
    } else {
        var -= 8;
        cout << "Parent ID: " << getpid() << endl;
        cout << "Parent: var = " << var << endl;
    }
}