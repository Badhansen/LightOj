// Solved
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ulng;
int t, test = 1;
ulng n, m;

ulng binomialCoeff(ulng n, ulng k)
{
    ulng res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ulng i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

ulng solve()
{
    scanf("%llu %llu", &n, &m);
    ulng ans = binomialCoeff(n, m);
    for(int i=0; i<m; ++i){
        ans *= (n-i);
    }
    printf("Case %d: %llu\n", test++, ans);
}
int main()
{
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}

