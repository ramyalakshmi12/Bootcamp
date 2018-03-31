#include <bits/stdc++.h>
#define LL long long
#define I int
#define LD long double
#define m(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define MAX 1000000007
#define INF 1e18+1

#define cint(d) scanf("%d", &d)
#define clong(d) scanf("%lld", &d)
#define cslong(d) scanf("%ld", &d)
#define pf printf

#define FOR(i, s, n) for(I i = s; i < n; i++)
#define FORR(i, n, s) for(I i = n-1; i >= s; i--)
#define v(i) vector<i>
using namespace std;

void zfunc(string s, I z[]) {
    int n = s.length();
    int L = 0, R = 0;
    z[0] = 0;
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
}

    I prefs[1000010];

int main() {
    
    I n;
    cint(n);
    I ar1[n];
    FOR(i, 0, n) {
        cint(ar1[i]);
    }
    for (int i = 1; i < n; ++i) {
        prefs[i + ar1[i] - 1] = max(prefs[i + ar1[i] - 1], ar1[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        prefs[i] = max(prefs[i+1] - 1, prefs[i]);
    }
    FOR(i, 0, n) {
        cout<<prefs[i]<<" ";
    }
}
