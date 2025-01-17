#include <iostream>
using namespace std;

void myFunction(){
    cout << "Function is working\n";
}

int main(void){
    int i;
    int* p;
    p = &i;
    i = 5;
    string name;

    cout << "Value of i: " << i << endl;
    cout << "Address of i: " << p << endl;
    cout << "Value of i: " << *p << endl;
    cout << "Address of i: " << &i << endl;

    myFunction();

    cout << "Enter your name: ";
    cin >> name;
    cout << name << endl;

    return 0;
}