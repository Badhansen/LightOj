// solved
#include<bits/stdc++.h>

using namespace std;
typedef long long lng;

vector<lng> v;
const lng MX = 1e12;
int sz;

void call(lng a)
{
    if(a > MX)
        return;
    if(a != 0) v.push_back(a);
    call(a * 10 + 4);
    call(a * 10 + 7);
}
void callNum(int idx, lng num)
{
    if(idx >= sz) return;
    for(int i=idx; i<sz; i++)
    {
        lng temp=num*v[i];
        if(temp<=0 || temp>MX) return;
        v.push_back(temp);
        callNum(i, temp);
    }
}
int main ()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    call(0);
    sort(v.begin(), v.end());
    sz = v.size();
    callNum(0, 1ll);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int t, ts = 1;
    scanf("%d", &t);
    while(t--){
        lng a, b;
        scanf("%lld%lld", &a, &b);
        int l = lower_bound(v.begin(), v.end(), a) - v.begin();
        int r = lower_bound(v.begin(), v.end(), b+1) - v.begin();
        //for(int i=0; i<20; i++) cout << v[i] << " ";
        printf("Case %d: %d\n", ts++, r - l);
    }
    return 0;
}

