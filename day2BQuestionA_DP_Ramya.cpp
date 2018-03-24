#include<bits/stdc++.h>
using namespace std;

long long dp0[102];
long long dp1[102];
int main() {
    int n, k;
    cin>>n>>k;
    dp0[0] = 0;
    dp1[0] = k - 1;
    for(int i = 1; i < n; i++) {
        dp0[i] = dp1[i - 1];
        dp1[i] = (dp0[i - 1] + dp1[i - 1]) * (k - 1);
    }
    cout<<(dp0[n - 1] + dp1[n - 1]);
}
