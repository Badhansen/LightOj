// Solved
#include<bits/stdc++.h>

using namespace std;

int n, t, test = 1;
int val[101];

void solve()
{
    int sum = 0, p = 0, ng = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &val[i]);
        sum += abs(val[i]);
        if(val[i]<0) ng++;
        else p++;
    }
    if(ng == n){
        printf("Case %d: inf\n", test++);
    }
    else{
        for(int i=2; i<=p; i++){
            if(sum%i==0 && p%i==0){
                while(sum%i==0 && p%i==0){
                    sum /= i;
                    p /= i;
                }
            }
        }
        printf("Case %d: %d/%d\n", test++, sum, p);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--){
        solve();
    }

    return 0;
}
