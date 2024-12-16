#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
struct matrix {
	int r, c;
	vector<vector<T>> A;

	matrix(int r, int c) : r(r), c(c) { A.resize(r, vector<T>(c,0)); }
	vector<T>& operator[](int i) { return A[i]; }

	static matrix identity(int n){
		matrix<T> id(n, n);
		for(int i = 0; i < n; i++)
			id[i][i] = 1;
		return id;
	}
	// Operaciones con matrices
	matrix operator+(matrix& B) {
		matrix C(r,c);
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				C[i][j] = A[i][j] + B[i][j];
		return C;
	}
	matrix operator-() {
		matrix<T> C(r, c);
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				C[i][j] = -A[i][j];
		return C;
	}
	matrix operator-(matrix& B) {
		return *this + (-B);
	}
	matrix operator*(matrix& B) {
		matrix<T> C(c, r);
		for(int i=0; i<r; i++)
			for(int j=0; j<B.c; j++)
				for(int k=0; k<c; k++)
					C[i][j] += A[i][k] * B[k][j];
		return C;
	}
	matrix operator*(T c) {
		matrix<T> C(c, r);
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				C[i][j] = A[i][j] * c;
		return C;
	}
	matrix operator^(ll p) {
		matrix<T> ans = matrix<T>::identity(r);
		matrix<T> A = *this;
		while(p){
			if(p & 1) ans = ans*A;
			p >>= 1;
			if(p) A = A*A;
		}
		return ans;
	}
};
template <typename T>
ostream &operator<<(ostream & os, matrix<T> & A){
	for(int i=0; i<A.r; i++){
		for(int j=0; j<A.c; j++)
			os << A[i][j] << " ";
		os << endl;
	} return os;
}

int main() {
	matrix<int> m(3,5);
	m[1][2] = 5;
	cout<<m<<endl;
	return 0;
}