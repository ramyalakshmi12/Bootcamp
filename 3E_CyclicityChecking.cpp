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
vector<int> vec[200010];
int visited[200010];
v(I) ans;
I found = 0;
I hold = 0;
void dfs(int s) {
    if(visited[s] == 2)
        return;
    
    if(visited[s] == 1) {
        found = 1;
        hold = s;
        ans.push_back(s);
        return;
    }
    visited[s] = 1;
    for(auto i: vec[s]) {
        if(found == 0)
            dfs(i);
    }
    if(found == 1) {
        ans.pb(s);
        if(s == hold)
            found = 2;
        return;
    }
    visited[s] = 2;
}

int main() {
    I n, m, t1, t2, t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i = 0; i < n + 1; i++) {
            vec[i].clear();
            visited[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            cin>>t1>>t2;
            vec[t1].push_back(t2);
        }
        for(int i = 1; i < n + 1; i++) {
            if(!visited[i]) {
                found = hold = 0;
                ans.clear();
                dfs(i);
                if(found != 0)
                    break;
            }
        }
        if(found != 0) {
            cout<<"NO\n"<<ans.size() - 1<<endl;
            for(int i = ans.size() - 1; i >= 0; i--) {
                cout<<ans[i]<<" ";   
            }
            cout<<endl;
        } else {
            cout<<"YES\n";
        }
        
    }
}
