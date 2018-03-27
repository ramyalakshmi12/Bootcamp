#include<bits/stdc++.h>
using namespace std;
vector<int> vec[200010];
int visited[200010];
int visited1[200010];
int n, m, c = 0;

void dfs(int s) {
    if(visited[s] == 1)
        return;
    visited[s] = 1;
    c++;
    for(auto i: vec[s]) {
            dfs(i);
    }
}

void dfs1(int s) {
    if(visited1[s] == c)
        return;
    visited1[s] = c;
    for(auto i: vec[s]) {
            dfs1(i);       
    }
}

int main() {
    string s;
    cin>>n>>m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            c = 0;
            dfs(i);
            dfs1(i);
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<visited1[i]<<" ";
}
