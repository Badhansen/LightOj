// Solved
#include<bits/stdc++.h>

using namespace std;
#define M 1001
struct edge{
    int u, v, w;
};
vector<edge> e;
vector<pair<int, int> > g[M];
set<int> path, t;
int dis[M];
bool vis[M];

void dfs(int s)
{
    vis[s] = true;
    t.insert(s);
    for(int i = 0; i < g[s].size(); i++){
        int v = g[s][i].first;
        if(!vis[v])
            dfs(v);
    }
}
void bellman_ford(int n, vector<edge> e, int s)
{
    int sz = e.size(), i, j, f = 0;
    for(i = 0; i <= n; i++){
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    for(i = 0; i < n; i++){
        f = 0;
        for(j = 0; j < sz; j++){
            int u, v, w;
            u = e[j].u;
            v = e[j].v;
            w = e[j].w;
            if(dis[u] != INT_MAX && dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                f = 1;
            }
        }
        if(!f) break;

    }
    memset(vis, false, sizeof vis);
    for(j = 0; j < sz; j++){
        int u, v, w;
        u = e[j].u;
        v = e[j].v;
        w = e[j].w;
        if(dis[u] != INT_MAX && dis[u]+w < dis[v]){
            dis[v] = dis[u]+w;
            dfs(u);
        }
        if(t.size() == 1){
            t.clear();
        }
        else{
            path.insert(t.begin(), t.end());
            t.clear();
        }
    }
}
void solve()
{
    int n, m, s;
    scanf("%d%d", &n, &m);
    s = n;
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        // creating a reverse graph for dfs
        g[v].push_back({u, w});
        // creating a reverse edge list for bellmond ford
        edge get;
        get.u = v;
        get.v = u;
        get.w = w;
        e.push_back(get);
        get.u = n;
        get.v = u;
        get.w = w;
        e.push_back(get);
        get.u = n;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    bellman_ford(n, e, s);
}
int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(ts <= t){

        solve();

        printf("Case %d: ", ts++);

        if(!path.size()){
            printf("impossible\n");
        }
        else{
            set<int> :: iterator it = path.begin();
            int len = path.size(), i = 0;
            for(it; it != path.end(); it++, i++){
                if(i == len-1){
                    printf("%d\n", *it);
                }
                else{
                    printf("%d ", *it);
                }
            }
        }
        for(int i = 0; i < M; i++){
            g[i].clear();
        }
        e.clear();
        path.clear();
    }


    return 0;
}
