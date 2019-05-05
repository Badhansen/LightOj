// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 201

struct edge{
    int u, v;
    long w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
vector<edge> e, temp;
int _find(int r)
{
    if(pr[r] == r)
        return r;
    return pr[r] = _find(pr[r]);
}
int kruskal(int n)
{
    temp.clear();
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++){
        pr[i] = i;
    }
    int cnt = 0, s = 0;
    int sz = e.size();
    for(int i = 0; i < sz; i++){
        int u = _find(e[i].u);
        int v = _find(e[i].v);
        if(u != v){
            cnt++;
            pr[u] = v;
            temp.push_back(e[i]);
            s += e[i].w;
            if(cnt == n-1){
                break;
            }
        }
    }
    e = temp;
    if(cnt == n-1){
        return s;
    }
    return -1;
}

void solve()
{

    int t, n, w, ts = 1;
    scanf("%d", &t);
    while(ts <= t){
        scanf("%d%d", &n, &w);
        printf("Case %d:\n", ts++);
        for(int i = 0; i < w; i++){
            int u, v;
            long w;
            scanf("%d%d%ld", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
            long ans = kruskal(n);
            printf("%ld\n", ans);
        }
        e.clear();
    }
}
int main()
{
    solve();
}


