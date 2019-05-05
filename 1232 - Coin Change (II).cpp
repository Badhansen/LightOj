// Solved
#include<bits/stdc++.h>

using namespace std;

#define M 100000007

typedef long long lng;

lng t, n, k;
lng coin[101];
lng dp[10001];
lng ways(lng n, lng k)
{
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(coin[i] <= j){
               dp[j] = (dp[j] % M + dp[j-coin[i]] % M) % M;
            }
        }
    }
    return dp[k];

}
int main ()
{

    lng cnt=1;
    scanf("%lld", &t);
    while(cnt <= t){
        scanf("%lld%lld", &n, &k);
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++){
            scanf("%lld", &coin[i]);
        }
        lng ans=ways(n, k);
        printf("Case %lld: %lld\n", cnt++, ans);
    }

    return 0;
}



