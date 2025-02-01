#include "Point3D.hpp"
#include <iostream>

using namespace std;

int main(void){
    Point3D p(1,2,3);
    Point3D* q;
    // p.x = 5;
    // p.y = -2;
    // p.z = 999;

    cout << p.x << endl;
    q = &p;
    q->x = 1000;

    cout << p.x << endl;

    IntArray* a = new IntArray(5);
    cout << a->data[3] << endl;

    delete a;

    // Point3D point{1, 2, 3};
    // cout << point.x << " " << point.y << " " << point.z << endl;

    // Point3D* r = new Point3D {7,7,7};

    // cout << r->x << " " << r->y << " " << r->z << endl;

    // delete r;

    // r = NULL;

    // delete r;

    int* dynamicArray = new int[5];

    for (int i = 0; i < 5; i++){
        dynamicArray[i] = i;
    }

    for (int i = 0; i < 5; i++){
        cout << dynamicArray[i] << " " << endl;
    }

    delete dynamicArray;
    dynamicArray = NULL;
    delete dynamicArray;

    // for (int i = 0; i < 5; i++){
    //     cout << dynamicArray[i] << " " << endl;
    // }

    // cout << r->x << endl;    


    // Point3D orig;
    // cout << orig.x << " " << orig.y << " " << orig.z << endl;


    return 0;
}