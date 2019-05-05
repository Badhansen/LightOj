// Solved
#include <bits/stdc++.h>

using namespace std;

int t, n, r, c;
vector<int> val[21];
int dp[21][3];

int call(int i, int j)
{
    if((i >= 0 && i < n) && (j >= 0 && j < 3)){
        int& ret=dp[i][j];
        if(ret != -1)
            return ret;
        int r1=0, r2=0;
        if(j == 0){
            r1 = call(i+1, j+1) + val[i][j];
            r2 = call(i+1, j+2) + val[i][j];
        }
        if(j == 1){
            r1 = call(i+1, j-1) + val[i][j];
            r2 = call(i+1, j+1) + val[i][j];
        }
        if(j == 2){
            r1 = call(i+1, j-1) + val[i][j];
            r2 = call(i+1, j-2) + val[i][j];
        }
        return ret = min(r1, r2);
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
    //freopen("in.txt", "r", stdin);
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



