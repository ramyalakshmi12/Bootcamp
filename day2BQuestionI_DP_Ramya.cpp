#include<bits/stdc++.h>
using namespace std;

long long dp[102][102];
void ncr(int n, int r) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= r; j++) {
            if(j == 0)
                dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i][j - 1] * (i - j + 1)) / j;
            }
        }
    }
}
int main() {
    int n, k;
    cin>>n>>k;
    int a[k];
    memset(dp, 0, sizeof(dp));
    ncr(31, 31);
    for(int i = 0; i < k; i++)
        cin>>a[i];
    long long sum = 0;
    long long prev = 1;
    for(int i = 0; i < k; i++) {
        if(i != 0) 
            prev = a[i - 1];
        for(int j = prev; j < a[i]; j++) {
            int l = k - i - 1;
            int r = n - j + 1;
            sum += dp[r + l - 1][l];
        }
    }
    cout<<sum;
}
