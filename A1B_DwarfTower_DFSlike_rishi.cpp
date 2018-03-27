#include <bits/stdc++.h>
#define LL long long
#define L long
#define I int
#define LD long double
#define m(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define p(a, b) pair<a, b>
#define MAX 1000000007
#define INF (1e18 + 1)
#define height_segTree(n) (int)(ceil(log2(n)))
#define max_size_segTree(n) 2*(int)pow(2, height_segTree(n)) - 1;

#define cint(d) scanf("%d", &d)
#define clong(d) scanf("%lld", &d)
#define cslong(d) scanf("%ld", &d)
#define pf printf

#define FOR(i, s, n) for(LL i = s; i < n; i++)
#define FORR(i, n, s) for(I i = n-1; i >= s; i--)
#define v(i) vector<i>
#define N 1100
using namespace std;
set<p(I, I)> se;
I d[200010];
v(p(I, I)) vec[200010];

int main() {
    I n, m, t1, t2, t3;
    cint(n);
    cint(m);
    FOR(i, 1, n + 1) {
        cint(t1);
        d[i] = t1;
        se.insert({t1, i});
    }
    FOR(i, 1, m + 1) {
        cint(t1);
        cint(t2);
        cint(t3);
        vec[t2].pb({t1, t3});
        vec[t3].pb({t1, t2});
    }
    while(!se.empty()) {
        set<p(I, I)>::iterator  it = se.begin();
        se.erase(it);
        for(auto i: vec[(*it).second]) {
            p(I, I) v = {d[i.first], i.first};
            if(se.find(v) == se.end()) continue;
            se.erase(v);
            d[i.first] = min(d[i.first], d[i.second] + d[(*it).second]);
            se.insert({d[i.first], i.first});
        }
    }
    cout<<d[1];
}
