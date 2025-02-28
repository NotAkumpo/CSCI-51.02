#include <iostream>
#include <cmath>
using namespace std;

struct Point3D{
    int x;
    int y;
    int z;
};

int getMD(Point3D p, Point3D q){
    return abs(p.x - q.x) + abs(p.y - q.y) + abs(p.z - q.z);
}

int main (void){
    // Number of test cases
    int t;
    cin >> t;

    // Number of points
    int p;

    // Coordinates of points
    int c;

    // Loop for each test case
    for (int i=0; i<t; i++){
        cin >> p;

        // Make an array of p points
        Point3D points[p];
        // Set coordinates of each point
        for (int i=0; i<p; i++){
            cin >> points[i].x >> points[i].y >> points[i].z;
        }

        // Get mannhattan distances
        for (int i=0; i<p-1; i++){
            cout << getMD(points[i], points[i+1]) << endl;
        }

        // Separate test cases with a single blank line
        if (i < (t-1)){
            cout << endl;
        }
    }
}