#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct point {
    ld x, y;
    point() : x(0) , y(0) {}
    point(ld x, ld y) : x(x) , y(y) {}

    point operator+(const point &p) const { return point(x+p.x, y+p.y); }
    point operator-(const point &p) const { return point(x-p.x, y-p.y); }

    ld cross(const point &p) { return x*p.y - y*p.x; }
};

ld triangleArea(const point &a, const point &b, const point &c ) {
    return abs((b-a).cross(c-a))/2;
}

int main() {
    return 0;
}