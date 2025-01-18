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

    cout << "\nMore pointer practice\n";
    string x = "LeBron James";
    string* y = &x;
    cout << "The GOAT: " << x << endl;
    cout << "LeBron lives here: " << y << endl;
    cout << "Refer to LeBron using his address: " << *y << endl;
    cout << "Find LeBron's address using him: " << &x << endl;
    printf("\n");

    myFunction();

    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello " << name << endl;

    return 0;
}