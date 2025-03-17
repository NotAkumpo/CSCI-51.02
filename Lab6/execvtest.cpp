#include <iostream>
#include <unistd.h> // some Unix stuff
using namespace std;

int main(int argc, char *argv[]){
    // if (execv("/usr/bin/gedit", argv) == -1){
    //     cout << "Error" << endl;
    // }
    if (execl("/usr/bin/gedit", "REALLY NOT GEDIT", NULL) == -1){
        cout << "Error" << endl;
    }
    cout << "Will this line still be printed?" << endl;
}