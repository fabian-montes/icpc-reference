#include <bits/stdc++.h>
using namespace std;

template<typename T, int SZ>
struct SegmentTree {
    struct Node {
        T value, lazy;
        Node() : value(0), lazy(0) {}
    };
    vector<Node> ST;
    vector<T> A;

    SegmentTree(vector<T> &arr) {
        ST.resize(4*SZ); A.resize(SZ, 0);
        copy(arr.begin(), arr.end(), A.begin());
    }
    void build(int pos=1, int lb=0, int rb=SZ-1) {
        if(lb == rb) { ST[pos].value = A[lb]; return; }
        int half = (lb+rb)>>1;
        build(pos<<1, lb, half); build(pos<<1 | 1, half+1, rb);
        ST[pos].value = ST[pos<<1].value + ST[pos<<1 | 1].value;
    }
    // point update A[i] <- value
    void update(int i, T value, int pos=1, int lb=0, int rb=SZ-1) {
        if(i==lb && i==rb) { ST[pos].value = A[lb] = value; return; }
        int half = (lb+rb)>>1;
        if(i<=half) update(i, value, pos<<1, lb, half);
        else update(i, value, pos<<1 | 1, half+1, rb);
        ST[pos].value = ST[pos<<1].value + ST[pos<<1 | 1].value;
    }

    T query(int l, int r, int pos=1, int lb=0, int rb=SZ-1) {
        if(lb>=l && rb<=r) return ST[pos].value;
        if(r<lb || rb<l) return 0;
        int half = (lb+rb)>>1;
        return query(l,r,pos<<1,lb,half) + query(l,r,pos<<1 | 1,half+1,rb);
    }
};

int main() {

    return 0;
}