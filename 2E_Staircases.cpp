#include<bits/stdc++.h>
using namespace std;

long long dp[102][102];
int main() {
    int n;
    cin>>n;
    
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(i == 0)
                dp[i][j] = 1;
            else {
                if(i >= j)
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    cout<<dp[n][n];
}
