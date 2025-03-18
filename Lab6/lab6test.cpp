#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){

    cout << "Hello, World!" << endl;

    // if( fork() == 0 ) {
    //     cout << "do stuff" << endl;
    // }
    // else if( fork() == 0 ) {
    //     cout << "do more stuff" << endl;
    // }
    // else if( fork() == 0 ) {
    //     cout << "do even more stuff" << endl;    
    // }
    // else if( fork() == 0 ) {
    //     cout << "noooo" << endl;
    // }

    if( fork() == 0 ) {
        cout << "fork 1" << endl;
        if( fork() == 0 ) {
            cout << "fork 2" << endl;
            if ( fork( ) == 0 ) {
                cout << "fork 3" << endl;
                cout << "if... aaaahhhh" << endl;
            }
        }
    }

    cout << "stuff outside of if statements" << endl;

    return 0;

}