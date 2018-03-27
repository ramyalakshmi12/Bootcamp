#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec[200010];
vector<int> ans;
int dep[200010];
int fup[200010];
int visited[200010];
int count = 0;
void dfs(int s, int p, int d) {
    visited[s] = 1;
    dep[s] = fup[s] = d;
    for(auto i: vec[s]) {
        //cout<<i.first<<" "<<i.second<<endl;
        if(i.first == p) continue;
        if(visited[i.first] == 1)
            fup[s] = min(fup[s], dep[i.first]);
        else {
            dfs(i.first, s, d + 1);
            if(fup[i.first] > dep[s])
                ans.push_back(i.second);
            fup[s] = min(fup[s], fup[i.first]);
        }        
    }
}

int main() {
    int n, m, t1, t2;
    cin>>n>>m;
    for(int i = 1; i < m + 1; i++) {
        cin>>t1>>t2;
        vec[t1].push_back({t2, i});
        vec[t2].push_back({t1, i});
    }
    for(int i = 1; i < n + 1; i++) {
        if(!visited[i])
            dfs(i, i, 0);
    }
    if(ans.size() > 0) {
        sort(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(int i = 0; i < ans.size(); i++)
            cout<<ans[i]<<" ";
    }
    else
        cout<<"0";
}
