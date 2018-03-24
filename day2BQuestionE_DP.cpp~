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
int dp[102][102];

int main() {
    I n;
    cint(n);
    FOR(i, 0, n + 1) {
        FOR(j, 0, n + 1) {
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
    cout<<dp[100][100]<<endl;
}


