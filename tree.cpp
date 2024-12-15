#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long int lli;
typedef pair<int,int> pii;

struct Tree {
	int N;
	vector<vector<int>> AdjList;

	Tree(int N) : N(N) { AdjList.resize(N); }
	vector<pii> eulerTour(int root) {
		vector<bool> v(N, false);
		vector<pii> tour_index(N);
		vector<int> its(N);
		stack<int> st;

		for(int i=0; i<N; i++) its[i]=AdjList[i].size()-1;

		st.push(root);
		int step = 0;
		while(!st.empty()) {
			int x = st.top();
			if(!v[x]) tour_index[x].F = step++;
			// cout<<"->"<<x<<endl; // orden de visita
			v[x] = true;

			while(its[x]>=0 && v[AdjList[x][its[x]]]) its[x]--;
			if((its[x]) >= 0) st.push(AdjList[x][its[x]]);

			if(its[x] < 0) st.pop(), tour_index[x].S=step-1;
		}
		return tour_index;
	}
};

int main() {
	int n; cin>>n;
	Tree tree(n);
	vector<bool> visited(n, false);
	for(int i=0; i<n-1; i++) {
		int u, v; cin>>u>>v; u--; v--;
		visited[v] = true;
		tree.AdjList[u].push_back(v);
		tree.AdjList[v].push_back(u);
	}
	int boss=-1; for(int i=0; i<n; i++) if(!visited[i]) boss=i;
	visited.assign(n, false);
	vector<pii> tour = tree.eulerTour(boss);

	for(pii p:tour) cout<<p.F<<' '<<p.S<<endl;

	return 0;
}