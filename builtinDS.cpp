#include <bits/stdc++.h>
using namespace std;

// codigo para arbol de PBDS
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

// operaciones de bits
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

int main() {
	return 0;
}