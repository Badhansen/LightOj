// Light-oj 1067 Combination
// Solved
#include<bits/stdc++.h>

using namespace std;

const int Maxn = 1e6 + 1, Mod = 1e6 + 3;
typedef long long lng;

lng fact[Maxn], ifact[Maxn], inv[Maxn];
int t, n, k, test;

void call()
{
    fact[0] = 1;
    for(int i=1; i<Maxn; i++){
        fact[i] = (fact[i-1] * i) % Mod;
    }
    ifact[0] = 1;
    inv[1] = 1;
    for(int i=2; i<Maxn; i++){
        inv[i] = ((Mod -(Mod/i)) % Mod * inv[Mod%i] % Mod) % Mod;
    }
    for(int i=1; i<Maxn; i++){
        ifact[i] = (ifact[i - 1] * inv[i]) % Mod;
    }
}

int NcR(int n, int r)
{
    int res = (1ll * ifact[r] * ifact[n-r]) % Mod;
    res = (1ll * res * fact[n]) % Mod;
    return res;
}
void solve()
{
    scanf("%d%d", &n, &k);
    printf("Case %d: %d\n", test++, NcR(n, k));
}
int main()
{
    test = 1;

    call();
    scanf("%d", &t);
    while(t--)
        solve();

    return 0;
}
