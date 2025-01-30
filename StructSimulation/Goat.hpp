#include <iostream>
#include <array>

using namespace std;

struct Goat{
    string name;
    int age;
    double ppg;
    // string children[3];

    Goat(string name, int age, double ppg){
        this->name = name;
        this->age = age;
        this->ppg = ppg;
    }
};