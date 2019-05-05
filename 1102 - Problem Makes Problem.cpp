// long long e memory limit exceeded
// but in some problem use long long fact and inv other wise stay sharp with overflow
// Solved
// 1102 Problem Makes Problem
// Full OK code for MOD is Prime
// If MOD is not prime Use Extended euclidean algorithm to calculate inverse
#include<bits/stdc++.h>

using namespace std;

#define Maxn 1000009
#define MOD 1000000007


int fact[2 * Maxn], inv[2 * Maxn];

int mPow(int a, int n)
{
    int ret = 1;
    while(n){
        if(n & 1) ret = (1ll * ret * a) % MOD;
        a = (1ll * a * a) % MOD; // for the case a = 10^18 then this will be a = ((a%MOD) * (a%MOD)) % MOD
        n >>= 1;
    }
    return ret;
}

void pre()
{
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    for(int i=2; i<2*Maxn; i++){
        fact[i] = (1ll * fact[i - 1] * i) % MOD;
        inv[i] = mPow(fact[i], MOD - 2);
    }
}
int NcR(int n, int r)
{
    if(n < r) return 0ll;
    int ret = (1ll * inv[r] * inv[n - r]) % MOD;
    ret = (1ll * fact[n] * ret) % MOD;
    return ret;
}
int NpR(int n, int r)
{
    if(n < r) return 0ll;
    int ret = (1ll * fact[n] * inv[n - r]) % MOD;
    return ret;
}
int main()
{
    pre();
    int t, ts = 1;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);
        k--;
        n += k;
        printf("Case %d: %lld\n", ts++, NcR(n, k));
    }

    return 0;
}
