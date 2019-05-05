#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, c, d, e, f;
ll dp[10008];

ll charom(ll a, ll b, ll c, ll d, ll e, ll f, ll n)
{
    ll i;
    dp[0]=a;
    dp[1]=b;
    dp[2]=c;
    dp[3]=d;
    dp[4]=e;
    dp[5]=f;
    for (i=6;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%10000007;
    }
    return dp[n];
}
int main() {
    ll n, caseno=0, cases;
    scanf("%lld", &cases);
    while(cases--) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        ll ck=charom(a, b, c, d, e, f, n)%10000007;
        printf("Case %lld: %lld\n", ++caseno, ck);
    }

    return 0;
}

