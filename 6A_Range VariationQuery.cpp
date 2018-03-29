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
LL lazy[1000000];
LL segTree2[1000000];
LL lazy2[1000000];
LL sq, sq1, sq2, sq3, sq4, sq5;

void segTree_build(I node, I low, I high){
    
    if(low == high){
        segTree[node] = ar[low];
    }else {
        I mid = (low + high) / 2;
        segTree_build(node*2 + 1, low, mid);
        segTree_build(node*2 + 2, mid + 1, high);
        
        segTree[node] = max(segTree[node*2 + 1], segTree[node*2 + 2]);
    }
    
}

void segTree_build2(I node, I low, I high){
    
    if(low == high){
        segTree2[node] = ar[low];
    }else {
        I mid = (low + high) / 2;
        segTree_build2(node*2 + 1, low, mid);
        segTree_build2(node*2 + 2, mid + 1, high);
        
        segTree2[node] = min(segTree2[node*2 + 1], segTree2[node*2 + 2]);
    }
    
}


void segTree_update(I node, I low, I high, I start, I end, LL val){
    if(low > high){
        return;
    }
    
    if(start > high || end < low){
        return;
    }
    
    segTree[node] = val;
    if(low != high) {
        I mid = (low + high) / 2;
        segTree_update(node*2 + 1, low, mid, start, end, val);
        segTree_update(node*2 + 2, mid + 1, high, start, end, val);

        segTree[node] = max(segTree[node*2 + 1], segTree[node*2 + 2]);
    }
}

void segTree_update2(I node, I low, I high, I start, I end, LL val){
    
    if(start > high || end < low){
        return;
    }
    
    segTree2[node] = val;
    if(low != high) {
        I mid = (low + high) / 2;
        segTree_update2(node*2 + 1, low, mid, start, end, val);
        segTree_update2(node*2 + 2, mid + 1, high, start, end, val);

        segTree2[node] = min(segTree2[node*2 + 1], segTree2[node*2 + 2]);
    }
}

long long segTree_query(I node, I low, I high, I start, I end){
    if(start > high || end < low)
        return -10000000000;
    
    if(start <= low && end >= high)
        return segTree[node];
    
    I mid = (low + high) / 2;
    return max(segTree_query(node*2 + 1, low, mid, start, end), segTree_query(node*2 + 2, mid + 1, high, start, end));
}

long long segTree_query2(I node, I low, I high, I start, I end){
    if(start > high || end < low)
        return 10000000000;
    
    if(start <= low && end >= high)
        return segTree2[node];
    
    I mid = (low + high) / 2;
    return min(segTree_query2(node*2 + 1, low, mid, start, end), segTree_query2(node*2 + 2, mid + 1, high, start, end));
}

int main() {
    I n, t1, t2;
    cint(n);
    FOR(i, 0, 1000000) {
        sq1 = (i + 1) % 12345;
        sq3 = (sq1 * sq1) % 12345;
        sq2 = (i + 1) % 23456;
        sq4 = (sq2 * sq2 * sq2) % 23456;
        sq5 = sq3 + sq4;
        ar[i] = sq5;
    }
    segTree_build(0, 0, 99999);
    segTree_build2(0, 0, 99999);
    while(n--) {
        cint(t1);
        cint(t2);
        if(t1 > 0) {
            LL ans1 = segTree_query(0, 0, 99999, t1 - 1, t2 - 1);
            LL ans2 = segTree_query2(0, 0, 99999, t1 - 1, t2 - 1);
            LL ans3 = ans1 - ans2;
            cout<<ans3<<endl;
        } else {
            segTree_update(0, 0, 99999, abs(t1) - 1, abs(t1) - 1, t2);
            segTree_update2(0, 0, 99999, abs(t1) - 1, abs(t1) - 1, t2);
        }
    }
    
}
