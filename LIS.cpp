#include <bits/stdc++.h>
using namespace std;

struct LIS {
	vector<vector<int>> lis, ptrs;
	vector<int> ins;
	int getLength() { return lis.size(); }

	void add(int x) {
		int inx = lower_bound(lis.begin(), lis.end(), x, [](const vector<int>& a, const int& x) {
			return x > a.back();
		}) - lis.begin();

		ins.push_back(inx);
		if(inx == lis.size()) {
			lis.push_back(vector<int>());
			ptrs.push_back(vector<int>());
		}
		lis[inx].push_back(x);
		if(inx > 0) ptrs[inx].push_back(lis[inx-1].size()-1);
	}
	void remove() {
		int inx = ins.back();
		if(!lis[inx].empty()) lis[inx].pop_back(), ptrs[inx].pop_back();
		if(lis[inx].empty()) lis.pop_back(), ptrs.pop_back();
		ins.pop_back();
	}
	vector<int> getSequence() {
		vector<int> res;
		int i = lis.size() - 1;
		int x = ptrs[i].size() - 1;
		while(i > 0) {
			res.push_back(lis[i][x]);
			x = ptrs[i][x];
			i--;
		}
		res.push_back(lis[i][x]);
		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	vector<int> a = {3,2,6,4,5,6,1,2,3,5,7,4,8,1,2,9};
	vector<int> b = {20,21};
	vector<int> c;
	LIS lis;

	for(int x:a) lis.add(x);
	cout<<lis.getLength()<<endl;
	
	c = lis.getSequence();
	for(int x:c) cout<<x<<' '; cout<<endl;

	for(int i=0; i<8; i++) lis.remove();
	c = lis.getSequence();
	for(int x:c) cout<<x<<' '; cout<<endl;

	for(int x:b) lis.add(x);

	c = lis.getSequence();
	for(int x:c) cout<<x<<' '; cout<<endl;

	return 0;
}