// Solved
// 1104 - Birthday Paradox
#include<bits/stdc++.h>

using namespace std;

const int Maxn = 1e5 + 1;
int t, n, test = 1;
int ans[Maxn];

void solve()
{
    float year = 1e5;
    ans[1]=1;
    for(int y=2; y<=year; y++){
        int p = 1;
        float res = 1.00;
        while(1){
            float x = y - p;
            x = (x/y);
            res = res * x;
            float temp = 1.00 - res;
            if(temp>=0.50){
                ans[y] = p;
                break;
            }
            p++;
        }

    }
}
int main()
{

    solve();
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", test++, ans[n]);
    }
    return 0;
}
