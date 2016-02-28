/*
copyright xu(xusiwei1236@163.com), all right reserved.

Max Points on a Line
=====================

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


/*
A*x + B*y + C = 0

=> A(x - x0) + B(y - y0) = 0

=> (x1 - x0)A + (y1 - y0)B = 0

etc.   6A + 8B = 0
A, B: 4, 3
*/
class Solution {
public:
    static int gcd(int a, int b) {
        return a ? gcd(b%a, a) : b;
    }

    int maxPoints(vector<Point> &points) {
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            int same = 1, mx = 0;
            unordered_map<string, int> count; 
            for (int j = i+1; j < points.size(); j++) {
                int a = points[i].x - points[j].x;
                int b = points[i].y - points[j].y;
                int g = gcd(a, b);
                
                if (!g) { same++; continue; }
                a /= g; b /= g;
                mx = max(mx, ++count[to_string(a) + ' ' + to_string(b)]); 
            }
            result = max(result, mx + same);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
#if 0
    int a = 42, b = 35;
    if (argc > 1) a = atoi(argv[1]);
    if (argc > 2) b = atoi(argv[2]);
    cout << Solution().gcd(a, b) << endl;
#endif
    vector<Point> points;
    int x, y;

    while (cin >> x >> y) {
        points.push_back(Point(x, y)); 
    }
    cout << Solution().maxPoints(points) << endl;
    return 0;
}

