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
long long dp[102][102];

long long calc(long long n, long long r) {
    if(r == 0) 
        return 1;
    if(dp[n][r])
        return dp[n][r];
    else {
        dp[n][r] = (calc(n, r - 1) * (n - r + 1)) / r;
        return dp[n][r];
    }
}

int main() {
    I n, k;
    cint(n);
    cint(k);
    I ar[k];
    FOR(i, 0, k) {
        cint(ar[i]);
    }
    dp[0][0] = 1;
    I prev = 1;
    LL ans = 0;
    FOR(i, 0, k) {
        if(i != 0) 
            prev = ar[i - 1];
        FOR(j, prev, ar[i]) {
            I a = n - j + 1;
            I b = k - i - 1;
            ans += calc(a + b - 1, b);
        }
    }
    cout<<ans<<endl;
}
