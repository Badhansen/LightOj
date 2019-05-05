// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 100001

struct edge{
    int u, v;
    long w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
vector<edge> e;
vector<int> g[MM];
bool vis[MM];
int airport;

int _find(int r)
{
    if(pr[r] == r)
        return r;
    return _find(pr[r]);
}
int kruskal(int n, int a)
{
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++){
        pr[i] = i;
    }
    int cnt = 0, s = 0;
    int sz = e.size();
    airport = 0;
    for(int i = 0; i < sz; i++){
        int u = _find(e[i].u);
        int v = _find(e[i].v);
        if(u != v){
            pr[u] = v;
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
            cnt++;
            s += e[i].w;
            if(e[i].w >= a){
                airport++;
                s += a;
                s -= e[i].w;
            }
            if(cnt == n-1){
                break;
            }
        }
    }
    return s;
}
void dfs(int u)
{
    vis[u] = true;
    for(int i = 0; i < g[u].size(); i++){
        if(!vis[g[u][i]]){
            dfs(g[u][i]);
        }
    }
}
void solve()
{

    int t, n, m, a, ts = 1;
    scanf("%d", &t);
    while(ts <= t){
        scanf("%d%d%d", &n, &m, &a);
        for(int i = 0; i < m; i++){
            int u, v;
            long w;
            scanf("%d%d%ld", &u, &v, &w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        long ans = kruskal(n, a);
        int cnt = 0;
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        ans += (a*cnt);
        printf("Case %d: %d %ld\n", ts++, ans, cnt+airport);
        e.clear();
        for(int i = 0; i < MM; i++) g[i].clear();
    }
}
int main()
{
    /*
        1059 - Air Ports	C++	0.828	7604	Accepted(scanf and printf)

        1059 - Air Ports	C++	0.840	7712	Accepted(fast I/O in main func)

        1059 - Air Ports	C++	0.808	7712	Accepted(fast I/O in solve func)
    */
    solve();
}

