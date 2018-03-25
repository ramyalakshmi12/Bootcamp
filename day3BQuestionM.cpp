#include<bits/stdc++.h>
using namespace std;
int n, m, c = 0;
int p[300010];
pair<int, int> t[300010];
int visited[300010];
vector<int> vec[300010];

void dfs(int s) {
    if(visited[s] == 1)
        return;
    visited[s] = 1;
    t[s].first = ++c;
    for(auto i: vec[s]) {
        dfs(i);
    }
    t[s].second = ++c;
}
int main() {
    int a, b;
    cin>>n;
    for(int i = 2; i <= n; i++) {
        cin>>p[i];
        vec[p[i]].push_back(i);
    }
    dfs(1);
    cin>>m;
    for(int i = 0; i < m; i++) {
        cin>>a>>b;
        if(t[a].first < t[b].first && t[a].second > t[b].second)
            cout<<"1\n";
        else if(t[a].first > t[b].first && t[a].second < t[b].second)
            cout<<"2\n";
        else
            cout<<"3\n";
    }
}
