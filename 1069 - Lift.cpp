// Solved
#include<bits/stdc++.h>

using namespace std;

int n, m, t, test;

void solve()
{
    scanf("%d%d", &n, &m);

    if(n<=m){
        int ans = 4*m + 19;
        printf("Case %d: %d\n", test++, ans);
    }
    else{
        int ans = 4*(2*n-m) + 19;
        printf("Case %d: %d\n", test++, ans);
    }
}
int main()
{
    test = 1;
    scanf("%d", &t);
    while(t--){
        solve();
    }

    return 0;
}
