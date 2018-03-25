#include<bits/stdc++.h>
using namespace std;
int ar[502][502];
int visited[502];
int k = 0;
int n;
stack<int> st, st2;

void dfs(int a, int b) {
    if(visited[a] == 1 || k == 1)
        return;
    visited[a] = 1;
    st.push(a);
    if(a == b) {
        k = 1;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(ar[a][i] == 1 && visited[i] == 0) 
            dfs(i, b);
    }
    if(k != 1) {
        st.pop();
    }
}

int main() {
    int a, b;
    cin>>n>>a>>b;
    if(a == b) {
        cout<<"0\n"<<a;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>ar[i][j];            
        }
    }
    dfs(a, b);
    if(k != 0) {
        cout<<st.size() - 1<<"\n";
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty()) {
            cout<<st2.top()<<" ";
            st2.pop();
        }
    }
    else {
        cout<<"-1";
    }
}
