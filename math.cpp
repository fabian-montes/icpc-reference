#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld f(ld x) { return x; } // funcion a evaluar

const int N = 1e6; // numero de pasos
ld simpson_integration(ld a, ld b) {
	ld h = (b - a) / N;
	ld s = f(a) + f(b);
	for(int i=1; i<N; i++) {
		ld x = a + h * i;
		s += f(x) * ((i&1) ? 4 : 2);
	} s *= h/3;
	return s;
}

const ld EPS = 1e-9;
ld ternary_search(ld l, ld r) {
	while(r-l > EPS) {
		ld m1 = l + (r - l)/3;
		ld m2 = r - (r - l)/3;
		ld f1=f(m1), f2=f(m2);
		f1<f2 ? l=m1 : r=m2;
	}
	return f(l); // maximo de f(x) en [l,r]
}

// y == 0 para buscar raiz
ld bisection_method(ld l, ld r, ld y=0) {
	while(r-l > EPS) {
		ld m = l + (r - l)/3;
		ld fm = f(m);
		fm<y ? l=m : r=m;
	}
	return l; // f(l) == f(y) en [l,r]
}

int main() {
	cout<<fixed<<setprecision(10);
	// cout<<simpson_integration(0,2)<<endl;
	// cout<<ternary_search(0,10)<<endl;
	// cout<<ternary_search(-5,10)<<endl;
	// cout<<round(bisection_method(0,10))<<endl; // buscar raiz dentro de l,r si existe
	// cout<<round(bisection_method(0,10,1))<<endl; // buscar l para f(l) == 1
	return 0;
}