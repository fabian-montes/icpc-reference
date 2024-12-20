#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long ll;

/* string hashing */
typedef pair<ll,ll> pll;

const pll B = {2543, 5471}; // base
const ll M = 1e9+7; // modulo

pll operator+(pll a, pll b) { return {(a.F+b.F)%M, (a.S+b.S)%M}; }
pll operator-(pll a, pll b) { return {(a.F-b.F+M)%M, (a.S-b.S+M)%M}; }
pll operator*(pll a, pll b) { return {(a.F*b.F)%M, (a.S*b.S)%M}; }
pll operator*(pll a, ll k) { return {(a.F*k)%M, (a.S*k)%M}; }
ostream &operator<<(ostream &os, const pll &p) { return os<<"{"<<p.F<<","<<p.S<<"}"; }

ll inv(ll a) { return a <= 1 ? a : M - (ll)(M/a) * inv(M%a) % M; }

struct RollingHash {
	vector<pll> H, P, I;
	int length;

	RollingHash(string s) {
		length = (int) s.size();
		H.resize(length+1); P.resize(length+1); I.resize(length+1);

		P[0] = I[0] = {1, 1};
		for(int i=1; i<=length; i++) {
			P[i] = P[i-1] * B;
			I[i] = {inv(P[i].F), inv(P[i].S)};
		}

		H[0] = {0, 0};
		int i = 1;
		for(char c:s) {
			H[i] = H[i-1] + (P[i] * (c-'A'+1));
			i++;
		}
	}

	// i&j inclusive and 1-indexed
	pll getSubstringHash(int i, int j) { return (H[j] - H[i-1]) * I[i-1]; }
	pll getSubstringHash(int i, int j) { return (H[j+1] - H[i]) * I[i]; } // s[i:j] 0-indexed
};

pll getHash(string s) {
	pll hash = {0, 0};
	pll P = B;
	for(int i=0; i<s.size(); i++) {
		hash = hash + (P*(s[i] - 'A'+1));
		P = P*B;
	}
	return hash;
}

int main() {
	return 0;
}