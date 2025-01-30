#include "Point3D.hpp"
#include <iostream>

using namespace std;

int main(void){
    Point3D p;
    Point3D* q;
    p.x = 5;
    p.y = -2;
    p.z = 999;

    cout << "Point: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    return 0;
}