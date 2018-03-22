#include <bits/stdc++.h>
#define LL long long
#define L long
#define I int
#define LD long double
#define m(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
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

I mat[N][N];
vector<int> vec[N];

int main() {
    I n, m, s, t, t1, t2;
    cint(n); cint(m);
    cint(s); cint(t);
    
    FOR(i, 0, m) {
        cint(t1); cint(t2);
        vec[t1].pb(t2);
        vec[t2].pb(t1);
        mat[t1][t2] = 1;
        mat[t2][t1] = 1;
    }
    
    queue<pair<int,int>>q1,q2;
	q1.push({s,0});
	q2.push({t,0});
	v(I) ar1(n+1,-1);
	v(I) ar2(n+1,-1);
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        if(ar1[curr.first] >= 0) continue;
        ar1[curr.first] = curr.second;
        for(auto i: vec[curr.first]) q1.push({i, curr.second + 1});
    }
    while(!q2.empty()) {
        auto curr = q2.front();
        q2.pop();
        if(ar2[curr.first] >= 0) continue;
        ar2[curr.first] = curr.second;
        for(auto i: vec[curr.first]) q2.push({i, curr.second + 1});
    }
    
    I ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            I k = min(ar1[i] + ar2[j] + 1, ar1[j] + ar2[i] + 1);
            if(mat[i][j] == 0 && mat[j][i] == 0 && k >= ar1[t]) {
                mat[i][j] = mat[j][i] = 1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
