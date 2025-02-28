#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
    int x, y, z;
};

int manhattanDistance(const Point3D& p1, const Point3D& p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        if (t > 0) cout << endl; // Separate test cases with a blank line

        int N;
        cin >> N;

        Point3D points[N];

        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y >> points[i].z;
        }

        for (int i = 0; i < N - 1; ++i) {
            cout << manhattanDistance(points[i], points[i + 1]) << endl;
        }
    }

    return 0;
}
