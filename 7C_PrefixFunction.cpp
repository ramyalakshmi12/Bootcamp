#include <bits/stdc++.h>
#define LL long long
#define L long
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

int main() {
    
    I n;
    string s1;
    cin>>s1;
    I len1 = s1.length();
    I ar1[len1 + 1];
    I j = 0;
    ar1[j] = 0;
    FOR(i, 1, len1){
        if(s1[j] != s1[i]){
            if(j == 0)
                ar1[i] = 0;
            else {
                j = ar1[j - 1];
                i--;
            }
        }else {
            ar1[i] = j + 1;
            j++;
        }
    }
    FOR(i, 0, len1) {
        cout<<ar1[i]<<" ";
    }
}
