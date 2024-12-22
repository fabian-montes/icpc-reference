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
istream& operator>>(istream& in, point& p) { return in>>p.x>>p.y; }
ostream& operator<<(ostream& os, const point& p) { return os<<"("<<p.x<<","<<p.y<<")"; }

int sgn(ld x) {
	if(le(x,0)) return 1;
	if(ge(x,0)) return -1;
	return 0;
}

/* ORDENAMIENTOS */
void sortAlongLine(vector<point>& ps, const point& v) { // los puntos pertenecen a linea
	sort(ps.begin(), ps.end(), [v](const point& a, const point &b){
		return a.dot(v) < b.dot(v);
	});
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
	return abs((p-a).cross(v)) / v.length();
}
ld distancePointSegment(const point& a, const point& b, const point& p) {
	ld x = (b-a).dot(p)/(b-a).norm();
	ld d = distancePointLine((b-a), a, p);
	return (geq(x, 0) && leq(x, 1) ? d : min((a-p).length(), (b-p).length()));
}

int lineIntersection(const point& v1, const point& a1, const point& v2, const point& a2, point* p=NULL) {
	// r1 = v1*t + a1, r2 = v2*t + a2
	if(sgn(v1.cross(v2)) == 0) { // parallel lines
		ld t = (a2.x - a1.x) / v1.x;
		point p = v1*t + a1;
		if(p == a2) return -1; // infinite points
		return 0; // no intersection
	}
	if(p != NULL) *p = a1 + v1 * (a2-a1).cross(v2) / v1.cross(v2);
	return 1; // single intersection
}
int segmentIntersection(const point& a, const point& b, const point& c, const point& d, point* p=NULL) {
	// s1 = a->b, s2 = c->d
	int res = lineIntersection((b-a), a, (c-d), d, p);
	if(res == -1) {
		ld x1 = (b-a).dot(c)/(b-a).norm();
		ld x2 = (b-a).dot(d)/(b-a).norm();
		if(x1 > x2) swap(x1,x2); // x1<x2
		if(le(x2,0) || ge(x1,1)) return 0; // no intersection
		return -1; // infinite points
	} if(res == 1) {
		if(sgn((c-a).cross(b-a))!=sgn((d-a).cross(b-a)) // single intersection
		&& sgn((a-c).cross(d-c))!=sgn((b-c).cross(d-c))) return 1;
	}
	return 0;
}

const ld BOUND = 1e3; // construir rayo como segmento
pair<point,point> buildRay(point& v, point& a) { v = v.unit();
	ld dx = BOUND + (ge(v.x,0) ? -a.x : a.x);
	ld dy = BOUND + (ge(v.y,0) ? -a.y : a.y);
	ld f = min((neq(v.x,0) ? abs(dx/v.x) : INF), (neq(v.y,0) ? abs(dy/v.y) : INF));
	return {v*f, a};
}

/* CIRCULOS */
bool insideCircle(const point& c, const ld& r, const point& p) {
	return leq((p-c).length(), r);
}
ld distancePointCircle(const point& c, const ld& r, const point& p) {
	return max((ld)0, (p-c).length() - r);
}
point projectionPointCircle(const point& c, const ld& r, const point& p) {
	return c + (p-c).unit() * r;
}
vector<point> circleIntersection(const point& c1, const ld& r1, const point& c2, const ld& r2) {
	ld d = (c2-c1).length();
	ld s = (r1 + r2 + d) / 2;
	if(ge(d, r1+r2)) return {}; // no intersection
	ld y = 2 / d * sqrt(s*(s-r1)*(s-r2)*(s-d));
	ld x1 = sqrt(r1*r1 - y*y);
	point dir = (c2-c1).unit();
	point p = c1 + dir*x1;
	if(eq(y,0)) return {p}; // single intersection
	return {p + dir.perp()*y, p - dir.perp()*y}; // double intersection
}
vector<point> lineCircleIntersection(const point& v, const point& a, const point& c, const ld& r) {
	ld d = distancePointLine(v,a,c);
	if(ge(d, r)) return {};
	ld y = sqrt(r*r - d*d);
	point dir = (v.proj(c-a) + a - c).unit();
	point p = c + dir*d;
	if(eq(y,0)) return {p}; // single intersection
	return {p + dir.perp()*y, p - dir.perp()*y}; // double intersection
}
pair<point,point> pointsOfTangency(const point& c, const ld& r, const point& p){
	point v = (p-c).unit() * r;
	ld cos_theta = r / (p - c).length();
	ld ang = acos(max(-1.0, min(1.0, cos_theta)));
	return {c + v.rotate(-ang), c + v.rotate(ang)};
}
ld areaIntersection(const point& c1, const ld r1, const point& c2, const ld r2);

int main() {
	point a(0,0), b(1,1), c(0.5,0.5), d(3,3);
	point A(1,3), B(-3.92,1.08);
	// cout<<distancePointLine((b-a), a, c)<<endl;
	// vector<point> ans = circleIntersection(a,10,b,8);
	// vector<point> ans = circleIntersection(a,10,c,5);
	// vector<point> ans = lineCircleIntersection((B-A),A,a,10);
	// for(point& p:ans) cout<<p<<' '; cout<<endl;
	point p; int hasInt = segmentIntersection(a,b,c,d,&p);
	if(hasInt == 1) cout<<p<<endl;
	else if(!hasInt) cout<<"NO"<<endl;
	else cout<<"inf"<<endl;
	return 0;
}