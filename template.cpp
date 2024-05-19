#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

//g++ -D DEBUG file.cpp
#ifdef DEBUG
    #define debug(x) cerr<<#x<<" = "<<x<<endl;
#else
    #define debug(x)
#endif

#define forab(i,a,b) for(int i=a; i<b; i++)
#define forn(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define S second
#define F first

#define print_vi(vec) for(int v:vec) cout<<v<<' '; cout<<'\n';
#define print_vvi(mat) for(vi vec:mat) { print_vi(vec) } cout<<'\n';
#define print_pii(vp) for(pii p:vp) cout<<p.F<<' '<<p.S<<'\n'; cout<<'\n';

const ld eps = 1e-9;
const ld pi = acos(-1);
const int INF = 1<<31-1;
const int MOD = 1e9+7;

void solve() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout<<fixed<<setprecision(12); // config cout para flotantes
    int t=1; //cin>>t;
    while(t--) solve();
    return 0;
}