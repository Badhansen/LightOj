// solved
#include <bits/stdc++.h>

using namespace std;

int t, n, r, c;
vector<int> val[21];
int dp[21][3];

int call(int i, int j)
{
    if((i >= 0 && i < n) && (j >= 0 && j < 3)){
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(j == 0){
            dp[i][j] = min(call(i+1, j+1), call(i+1, j+2)) + val[i][j];
            return dp[i][j];
        }
        if(j == 1){
            dp[i][j] = min(call(i+1, j-1), call(i+1, j+1)) + val[i][j];
            return dp[i][j];
        }
        if(j == 2){
            dp[i][j] = min(call(i+1, j-1), call(i+1, j-2)) + val[i][j];
            return dp[i][j];
        }
    }
    else{
        return 0;
    }
}
void input()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++){

        for(int j=0; j<3; j++){
            int tem;
            scanf("%d", &tem);
            val[i].push_back(tem);
        }
    }
}
int main ()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test = 1;
    scanf("%d", &t);
    while(t--){
        for(int i=0; i<21; i++){
            val[i].clear();
        }
        input();
        memset(dp, -1, sizeof dp);
        int ans = min(call(0, 0), min(call(0, 1), call(0, 2)));
        printf("Case %d: %d\n", test++, ans);
    }
    return 0;
}

