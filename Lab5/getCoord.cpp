#include <iostream>
#include "getCoord_extern.cpp"
using namespace std;

int getCoord (Point3D p){
    return p.x;
}

int main(void){
    Point3D p;
    p.x = 5;
    p.y = 7;
    p.z = -2;
    cout << getCoord(p) << endl;
    return 0;
}
