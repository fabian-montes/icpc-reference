#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long lli;

/* string hashing */
typedef pair<lli,lli> pll;

const pll BASE = {2543, 5471};
const lli MOD = 1e9+7;

pll operator+(pll a, pll b) { return {(a.F+b.F)%MOD, (a.S+b.S)%MOD}; }
pll operator-(pll a, pll b) { return {(a.F-b.F+MOD)%MOD, (a.S-b.S+MOD)%MOD}; }
pll operator*(pll a, pll b) { return {(a.F*b.F)%MOD, (a.S*b.S)%MOD}; }
pll operator*(pll a, lli k) { return {(a.F*k)%MOD, (a.S*k)%MOD}; }
ostream &operator<<(ostream &os, const pll &p) { return os<<"{"<<p.F<<","<<p.S<<"}"; }

lli inv(lli a) { return a <= 1 ? a : MOD - (lli)(MOD/a) * inv(MOD%a) % MOD; }

struct RollingHash {
    vector<pll> H, P, I;
    int length;

    RollingHash(string s) {
        length = s.size();
        H.resize(length+1);
        P.resize(length+1);
        I.resize(length+1);

        P[0] = I[0] = {1, 1};
        for(int i=1; i<=length; i++) {
            P[i] = P[i-1]*BASE;
            I[i] = {inv(P[i].F), inv(P[i].S)};
        }

        H[0] = {0, 0};
        int i = 1;
        for(char c:s) {
            H[i] = H[i-1] + (P[i]*(c-'A'+1));
            i++;
        }
    }

    // i&j inclusive and 1-indexed
    pll getSubstringHash(int i, int j) { return (H[j]-H[i-1]) * I[i-1]; }
};

pll getHash(string s) {
    pll hash = {0, 0};
    pll P = BASE;
    for(int i=0; i<s.size(); i++) {
        hash = hash + (P*(s[i]-'A'+1));
        P = P*BASE;
    }
    return hash;
}

int main() {

    return 0;
}