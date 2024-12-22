#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define CA0 c-'a'

struct Trie {
	vector<vi> trie;
	vi isEndpoint;

	Trie() { trie.pb(vi(26,0)); isEndpoint.pb(1); }
	void add(const string& s) {
		int x = 0;
		for(char c:s) {
			if(trie[x][CA0]) x = trie[x][CA0];
			else {
				x = trie[x][CA0] = trie.size();
				trie.pb(vi(26,0));
				isEndpoint.pb(0);
			}
		}
		isEndpoint[x] = true;
	}
	bool search(const string& s) {
		int x = 0;
		for(char c:s) {
			if(!trie[x][CA0]) return false;
			x = trie[x][CA0];
		}
		return isEndpoint[x];
	}
};

int main() {
	Trie trie;
	trie.add("can");
	trie.add("candy");
	trie.add("canal");
	trie.add("candyrush");
	trie.add("there");

	cout<<trie.search("candyrush")<<endl;
	cout<<trie.search("can")<<endl;
	cout<<trie.search("love")<<endl;
	cout<<trie.search("ca")<<endl;
	cout<<trie.search("ther")<<endl;
	cout<<trie.search("there")<<endl;
	cout<<trie.search("")<<endl;
	return 0;
}