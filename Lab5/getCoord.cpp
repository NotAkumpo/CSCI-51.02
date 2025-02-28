#include <iostream>
#include "getCoord_extern.cpp"
using namespace std;

int getCoord (Point3D p){
    return p.x;
}

int delta(Point3D p, Point3D q){
    return p.x - q.x;
}

int main(void){
    Point3D p;
    p.x = 5;
    p.y = 7;
    p.z = -2;
    cout << getCoord(p) << endl;
    return 0;
}
