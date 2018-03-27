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

int main() {
    I n, m;
    cint(n);
    cint(m);
    LL ar[n], br[m];
    FOR(i, 0, n) {
        clong(ar[i]);
    }
    FOR(i, 0, m) {
        clong(br[i]);
    }
    sort(ar, ar+n, greater<int>());
    sort(br, br+m, greater<int>());
    LL ans = 1;
    FOR(i, 0, m) {
        ans += br[i];
    }
    LL need = m;
    LL j = 0, ansu = 1;
    FOR(i, 0, n) {
        LL k = ar[i];
        if(k != 0 && j < m){
            ansu--;
        while(k != 0 && j < m) {
            ansu += br[j];
            j++;
            k--;
        }
        }
    }
    cout<<ansu<<endl;
}
