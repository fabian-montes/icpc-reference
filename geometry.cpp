#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld PI = acos(-1);
const ld EPS = 1e-9;
const ld INF = numeric_limits<ld>::max();

/* OPERADORES RELACIONALES PARA ld */
bool eq(ld a, ld b) { return abs(a-b) <= EPS; }
bool neq(ld a, ld b) { return !eq(a,b); }
bool leq(ld a, ld b) { return b-a >= -EPS; }
bool geq(ld a, ld b) { return a-b >= -EPS; }
bool le(ld a, ld b) { return b-a > EPS; }
bool ge(ld a, ld b) { return a-b > EPS; }

/* ESTRUCTURA POINT */
struct point {
	ld x, y;
	point() : x(0), y(0) {}
	point(ld x, ld y) : x(x), y(y) {}

	point operator+(const point& p) const { return point(x+p.x, y+p.y); }
	point operator-(const point& p) const { return point(x-p.x, y-p.y); }
	point operator*(const ld& k) const { return point(x*k, y*k); }
	point operator/(const ld& k) const { return point(x/k, y/k); }

	point unit() const { return *this / length(); }
	point perp() const { return point(-y,x); }

	ld dot(const point& p) const { return x*p.x + y*p.y; }
	ld cross(const point& p) const { return x*p.y - y*p.x; }

	point proj(const point& p) const { return unit() * this->dot(p) / length(); } // proyecion de p sobre this
	point rotate(const ld& ang) const { return point(x*cos(ang)-y*sin(ang), x*sin(ang)+y*cos(ang)); }

	ld norm() const { return x*x + y*y; }
	ld length() const { return sqrtl(x*x + y*y); }

	ld ang(const point& p) const { return acos(this->dot(p) / length() / p.length()); }

	bool operator!=(const point& p) const { return !(*this == p); }
	bool operator==(const point& p) const { return eq(x,p.x) && eq(y,p.y); }
	bool operator<(const point& p) const { return (eq(x,p.x) ? le(y,p.y) : le(x,p.x)); }
	bool operator<=(const point& p) const { return (eq(x,p.x) ? leq(y,p.y) : leq(x,p.x)); }
	bool operator>(const point& p) const { return (eq(x,p.x) ? ge(y,p.y) : ge(x,p.x)); }
	bool operator>=(const point& p) const { return (eq(x,p.x) ? geq(y,p.y) : geq(x,p.x)); }
};
istream& operator>>(istream& CIN, point& p) { return CIN>>p.x>>p.y; }
ostream& operator<<(ostream& COUT, const point& p) { return COUT<<"("<<p.x<<","<<p.y<<")"; }

int sgn(ld x) {
	if(le(x,0)) return 1;
	if(ge(x,0)) return -1;
	return 0;
}

/* AREA DE POLIGONOS */
ld triangleArea(const point& a, const point& b, const point& c) {
	return abs((b-a).cross(c-a)) / 2; // implementacion rapida
}
ld shoelaceArea(const vector<point>& p) {
	ld area = 0;
	int n = (int) p.size();
	for(int i=0; i<n; i++)
		area += p[i].x*p[(i+1)%n].y - p[i].x*p[(i-1+n)%n].y;
	return area / 2;
}
ld perimeter(const vector<point>& p) {
	ld perimeter = 0;
	int n = (int) p.size();
	for(int i=0; i<n; i++)
		perimeter += (p[(i+1)%n]-p[i]).length();
	return perimeter;
}

/* LINEAS y SEGMENTOS */
ld distancePointLine(const point& v, const point& a, const point& p) {
	return (p-a).cross(v) / v.length();
}

const ld BOUND = 1e3; // construir rayo como segmento
pair<point,point> buildRay(point& v, point& a) { v = v.unit();
	ld dx = BOUND + (ge(v.x,0) ? -a.x : a.x);
	ld dy = BOUND + (ge(v.y,0) ? -a.y : a.y);
	ld f = min((neq(v.x,0) ? abs(dx/v.x) : INF), (neq(v.y,0) ? abs(dy/v.y) : INF));
	return {v*f, a};
}

/* CIRCULOS */
/* TRIANGULOS */
/* CUADRILATEROS */

int main() {

	return 0;
}