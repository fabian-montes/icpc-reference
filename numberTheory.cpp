#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }

ll binpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r *= b;
		e >>= 1;
		b *= b;
	}
	return r;
}

// {gcd, x, y} ax + by = gcd(a,b) = d
// x = x0 + (b/d)n : y = y0 - (a/d)n
tuple<ll,ll,ll> extendedGcd(ll a, ll b){
	if(b == 0)
		if(a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	auto [d, x, y] = extendedGcd(b, a%b);
	return {d, y, x - y*(a/b)};
}

vector<int> primes;
vector<int> primeSieve(int n) {
	vector<bool> isPrime(n, true);
	vector<int> primes;
	for(int i=2; i<=n; i++) {
		if(!isPrime[i]) continue;
		for(ll j=(ll)i*i; j<=n; j+=i) isPrime[j]=0;
		primes.push_back(i);
	}
	return primes;
}

// numPF(n) count number of prime factors of integer n
// numPF(n) contar numero de factores primos de n
vector<pair<int,int>> primeFactors(ll n) {
	vector<pair<int,int>> factors;
	for(int x:primes) {
		if((long long)x*x > n) break;
		int p=0; while(n%x == 0) n/=x, p++;
		if(p) factors.push_back({x,p});
	}
	if(n != 1) factors.push_back({n,1});
	return factors;
}

// numDiv(n) count number of divisors of integer n
// numDiv(n) contar numero de divisores de n
ll numDivisors(ll n) {
	ll ndivs=1; auto factors = primeFactors(n);
	for(auto f:factors) ndivs *= (f.second+1);
	return ndivs;
}

// sumDiv(n) count sum of divisors of n
// sumDiv(n) suma de los divisores de n
ll sumDivisors(ll n);

int main() {
	// primes = primeSieve(1e2);
	// for(int x:primes) cout<<x<<' '; cout<<endl;

	// vector<pair<int,int>> ans = primeFactors(1680000000000LL);
	// vector<pair<int,int>> ans = primeFactors(60);
	// for(auto p:ans) { cout<<p.first<<' '<<p.second<<endl; }
	// cout<<numDivisors(60)<<endl;
	auto [g,x,y] = extendedGcd(25,18);
	cout<<g<<' '<<x<<' '<<y<<endl;
	cout<<binpow(2,10)<<endl;
	return 0;
}