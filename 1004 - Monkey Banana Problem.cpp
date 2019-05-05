// Solved
#include <bits/stdc++.h>

using namespace std;

typedef long long lng;

lng t, n, r, c;
vector<lng> val[201];
lng dp[201][101];

lng call(int i, int j)
{
    if((i >= 0 && i < 2*n-1) && (j >= 0 && j < val[i].size())){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i < n-1){
            // i am still not reach in the middle
            dp[i][j] = max(call(i+1, j), call(i+1, j+1))+val[i][j];
            return dp[i][j];
        }
        else{
            // i am reach in the middle
            dp[i][j] = max(call(i+1, j), call(i+1, j-1))+val[i][j];
            return dp[i][j];
        }
    }
    else{
        return 0;
    }
}
void input()
{
    scanf("%lld", &n);

    int id = 1;
    bool flag = false;
    for(int i=0; i<2*n-1; i++){

        for(int j=0; j<id; j++){
            lng tem;
            scanf("%lld", &tem);
            val[i].push_back(tem);
        }
        if(id == n){
            flag = true;
        }
        if(flag){
            id--;
        }
        if(!flag){
            id++;
        }
    }
}
int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    lng test = 1;
    scanf("%lld", &t);
    while(t--){
        for(int i=0; i<201; i++){
            val[i].clear();
        }
        input();
        memset(dp, -1, sizeof dp);
        lng ans = call(0, 0);
        printf("Case %lld: %lld\n", test++, ans);
    }
    return 0;
}
