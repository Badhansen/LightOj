// Light-oj 1067 Combination
// Solved
#include<bits/stdc++.h>

using namespace std;

const int Maxn = 1e6 + 1, Mod = 1e6 + 3;

int fact[Maxn], ifact[Maxn], inv[Maxn];
int t, n, k, test;

template<typename T, typename T1> T mod(T x, T1 p)
{
    x %= p;
    if (x < 0)
        x += p;
    return x;
}

// x must be relatively prime to p
template<typename T> T inverse(T x, T p)
{
    x = mod(x, p);
    if (x == 1)
        return x;
    return mod(1LL * (-p / x) * (inverse(p % x, p)) , p);
}

void call()
{

    fact[0] = 1;
    for(int i = 1; i < Maxn; i++) {
        fact[i] = 1LL * fact[i - 1] * i % Mod;
    }
    ifact[0] = 1;
    for(int i = 1; i < Maxn; i++) {
        ifact[i] = 1LL * ifact[i - 1] * inverse(i, Mod) % Mod;
    }
}

int NcR(int n, int r) {
    int ret = (1LL * ifact[n - r] * ifact[r]) % Mod ;
	ret = (1LL * ret * fact[n]) % Mod;
    return ret;
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


