#include <bits/stdc++.h>
using namespace std;

/* codigo para arbol de PBDS */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;

typedef int TYPE;
typedef tree<TYPE, null_type, less<TYPE>, rb_tree_tag,
			 tree_order_statistics_node_update>
	ordered_set;

ordered_set mySet; // declarar objeto
// mySet.insert(x); // insertar x a la coleccion
// mySet.erase(x); // eliminar todas las ocurrencias de x
// mySet.order_of_key(x); // cuenta el numero de elementos menores a x
// mySet.find_by_order(x); // devuelve iterador al valor conatando desde 0

/* OPERACIONES DE BITS */
#pragma GCC target("popcnt") // bitset con int bitwise (faster)
// donde s es un arreglo de bits e i un iterador entero
// s&(1<<i) // condicion i es verdadero
// s<<=1; s>>=1; // multiplicacion / division
// s|=(1<<i); // encender i-esimo bit
// s&=~(1<<i); // apagar i-esimo bit
// s^=(1<<i); // cambiar estado de i
// s=(1<<n)-1; // encender todos los bits hasta n
// sizeof(TYPE) // numero de bytes del tipo de dato
// __builtin_popcount(s); // contar bits encendidos
// __builtin_parity(s); // la cantidad de unos es par o impar
// __builtin_ctz(s); // contar trailing zeros
// __builtin_clz(s); // contar leading zeros
// para ll -> builtin_*ll()
// int lsb=((s)&(-s)); // bit menos significativo 
// cout<<bitset<32>(s)<<endl; // imprimir bits

/* UNION FIND */
struct UnionFind {
	vector<int> p, sz, rank;
	int numSets;
	UnionFind(int n) : numSets(n) {
		p.assign(n,0); for(int i=0; i<n; i++) p[i]=i;
		rank.assign(n,0); sz.assign(n,1);
	}

	int find(int x) { while(x != p[x]) x = p[x]; return x; }
	bool isSame(int x, int y) { return find(x) == find(y); }
	int setSize(int x) { return sz[find(x)]; }

	void join(int x, int y) {
		if(isSame(x, y)) return;
		int i = find(x), j = find(y);
		if(rank[i] > rank[j]) swap(i, j);
		if(rank[i] == rank[j]) rank[j]++;
		sz[j] += sz[i];
		p[i] = j;
		numSets--;
	}
};

/* SPARSE TABLE */
template <class T>
struct SparseTable {
	vector<vector<T>> st;
	vector<T> A;

	SparseTable(vector<T>& a) : A(a) {
		int N=a.size(), K=log2_floor(N);
		st.resize(K+1, vector<T>(N)); st[0]=A;
		for(int i=1; i<=K; i++)
			for(int j=0; j+(1 << i) <= N; j++)
				st[i][j] = min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
	}
	T query(int l, int r) {
		int i = log2_floor(r - l + 1);
		return min(st[i][l], st[i][r - (1 << i) + 1]);
	}

	int log2_floor(int i) { return i ? __builtin_clz(1) - __builtin_clz(i) : -1; }
};

int main() {
	return 0;
}