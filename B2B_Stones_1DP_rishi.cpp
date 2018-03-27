#include <bits/stdc++.h>
#define LL long long
#define L long
#define I int
#define LD long double
#define LLD long double
#define m(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define MAX 1000000007
#define INF (1e18 + 1)
#define height_segTree(n) (int)(ceil(log2(n)))
#define max_size_segTree(n) 2*(int)pow(2, height_segTree(n)) - 1; 

#define cint(d) scanf("%d", &d)
#define clong(d) scanf("%lld", &d)
#define cflong(d) scanf("%llf", &d)
#define cslong(d) scanf("%ld", &d)
#define pf printf

#define FOR(i, s, n) for(LL i = s; i < n; i++)
#define FORR(i, n, s) for(I i = n-1; i >= s; i--)
#define v(i) vector<i>
#define N 1100
using namespace std;
long long dp0[100];
long long dp1[100];

int main() {
    I n;
    cint(n);
    if(n%3 == 0) {
        cout<<"2";
    }else {
        cout<<"1";
    }
}
