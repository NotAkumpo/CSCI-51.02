#include "Goat.hpp"
#include <iostream>

using namespace std;

int main(void){
    Goat lbj("LeBron James", 40, 31.6);
    cout << "Name: " << lbj.name << endl;
    cout << "Age: " << lbj.age << endl;
    cout << "PPG: " << lbj.ppg << endl;

    return 0;
}