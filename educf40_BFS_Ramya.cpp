#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int mat[1010][1010] = {0};

int main() {
    int n, m, s, t, x, y; 
    cin>>n>>m>>s>>t;
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    queue<pair<int, int>> q1, q2;
    q1.push({s, 0});
    q2.push({t, 0});
    vector<int> a1(n + 1, -1), a2(n + 1, -1);
    
    while(!q1.empty()) {
        auto curr = q1.front();
        q1.pop();
        if(a1[curr.first] != -1) continue;
        a1[curr.first] = curr.second;
        for(auto i: v[curr.first]) q1.push({i, curr.second + 1});
        
    }
    
    while(!q2.empty()) {
        auto cur = q2.front();
        q2.pop();
        if(a2[cur.first] != -1) continue;
        a2[cur.first] = cur.second;
        for(auto i: v[cur.first]) q2.push({i, cur.second + 1});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            int k = min(a1[i] + a2[j] + 1, a1[j] + a2[i] + 1);
            if(mat[i][j] == 0 && mat[j][i] == 0 && k >= a1[t]) {
                mat[i][j] = mat[j][i] = 1;
                ans++;
            }
        }
    }
    cout<<ans;
}
