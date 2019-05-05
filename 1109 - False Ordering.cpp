// Solved
#include<bits/stdc++.h>

using namespace std;
int t, test, n;

bool dp[1001];
int prime[1001];
vector<pair<int, int> > v;

void seive()
{
    memset (dp, false, sizeof (dp));
    int ck, i, j, k;
    ck=sqrt(1000);
    for (i=4; i<=1000; i+=2){
        dp[i]=true;
    }
    prime[0]=2;
    for (i=3, k=1; i<=1000; i+=2){
        if (dp[i]==false){
            prime[k++]=i;
            for (j=i*i; j<=1000; j+=i){
                dp[j]=true;
            }
        }
    }
}
int numDiv(int n)
{
    int prime_factor, ans=1, prime_id=0;
    prime_factor=prime[prime_id];
    while (prime_factor*prime_factor<=n){
        int power=0;
        while (n%prime_factor==0){
            n/=prime_factor;
            power++;
        }
        ans*=(power+1);
        prime_factor=prime[++prime_id];
    }
    if (n!=1) ans*=2; // last prime has a power of 1 and we add 1 as same rule
    return ans;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first==b.first){
        if(a.second>b.second){
            return true;
        }
        else return false;
    }
    else if(a.first<b.first){
        return true;
    }
    else return false;
}
void solve()
{
    for(int i=1; i<=1000; i++){
        v.push_back(make_pair(numDiv(i), i));
    }
    sort(v.begin(), v.end(), cmp);
}
int main()
{
    test = 1;
    seive();
    solve();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        n--;
        printf("Case %d: %d\n", test++, v[n].second);
    }

    return 0;
}
