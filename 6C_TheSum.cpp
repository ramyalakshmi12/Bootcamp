#include <bits/stdc++.h>
#define LL long long
#define L long
#define I int
#define LD long double
#define m(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define MAX 1000000007
#define INF 1e18+1
#define height_segTree(n) (int)(ceil(log2(n)))
#define max_size_segTree(n) 2*(int)pow(2, height_segTree(n)) - 1; 

#define cint(d) scanf("%d", &d)
#define clong(d) scanf("%lld", &d)
#define cslong(d) scanf("%ld", &d)
#define pf printf

#define FOR(i, s, n) for(I i = s; i < n; i++)
#define FORR(i, n, s) for(I i = n-1; i >= s; i--)
#define v(i) vector<i>
using namespace std;

LL ar[1000000];
LL segTree[1000000];
LL lazy[1000000] = {-1};

void segTree_build(I node, I low, I high){
    
    if(low == high){
        segTree[node] = ar[low];
    }else {
        I mid = (low + high) / 2;
        segTree_build(node*2 + 1, low, mid);
        segTree_build(node*2 + 2, mid + 1, high);
        
        segTree[node] = segTree[node*2 + 1] + segTree[node*2 + 2];
    }
    
}


void segTree_update(I node, I low, I high, I start, I end, LL val){
    if(low > high){
        return;
    }
    
    if(lazy[node] != -1){
        segTree[node] = 1LL * (high - low + 1) * lazy[node];
        if(low != high){
            lazy[node*2 + 1] = lazy[node];
            lazy[node*2 + 2] = lazy[node];
        }
        lazy[node] = -1LL;
    }
    
    if(start > high || end < low){
        return;
    }
    
    if(start <= low && end >= high){
        segTree[node] = 1LL * (high - low + 1) * val;
        if(low != high){
            lazy[node*2 + 1] = val;
            lazy[node*2 + 2] = val;
        }
        return;
    }
    I mid = (low + high) / 2;
    segTree_update(node*2 + 1, low, mid, start, end, val);
    segTree_update(node*2 + 2, mid + 1, high, start, end, val);
    
    segTree[node] = segTree[node*2 + 1] + segTree[node*2 + 2];
}

long long segTree_query(I node, I low, I high, I start, I end){
    
    if(lazy[node] != -1){
        segTree[node] = 1LL * (high - low + 1) * lazy[node];
        if(low != high){
            lazy[node*2 + 1] = lazy[node];
            lazy[node*2 + 2] = lazy[node];
        }
        lazy[node] = -1LL;
    }
    
    if(start > high || end < low)
        return 0;
    
    if(start <= low && end >= high)
        return segTree[node];
    
    I mid = (low + high) / 2;
    return (segTree_query(node*2 + 1, low, mid, start, end) + segTree_query(node*2 + 2, mid + 1, high, start, end));
}
int main() {
    I n, q, t1, t2, t3; char c;
    m(lazy, -1);
    cint(n);
    cint(q);
    while(q--) {
        cin>>c;
        if(c == 'A') {
            cint(t1); cint(t2); cint(t3);
            segTree_update(0, 0, n - 1, t1 - 1, t2 - 1, t3);
        } else {
            cint(t1); cint(t2);
            cout<<segTree_query(0, 0, n - 1, t1 - 1, t2 - 1)<<"\n";
        }
    }
    
}
