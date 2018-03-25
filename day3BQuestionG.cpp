#include<bits/stdc++.h>
using namespace std;
char ar[1005][1005];
int br[1005][1005];
vector<int> vec;
int c = 0, n, m;
void dfs(int i, int j) {
    if(i >= n || j >= m || i < 0 || j < 0)
        return;
    if(ar[i][j] == '*' || br[i][j] == 1)
        return;
    if(ar[i][j] == '.') {
        br[i][j] = 1;
        c++;
    }
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}
int main() {
    string s;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>s;
        for(int j = 0; j < m; j++) {
            ar[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ar[i][j] == '.' && br[i][j] == 0) {
                c = 0;
                dfs(i, j);
                vec.push_back(c);
            }
        }
    }
    if(vec.size() != 0) {
        cout<<vec.size()<<"\n";
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++)
            cout<<vec[i]<<" ";
    }
    else
        cout<<"0";
}
