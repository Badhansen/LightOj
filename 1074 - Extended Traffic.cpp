// Solved
#include<bits/stdc++.h>

using namespace std;
#define M 201
struct edge{
    int u, v, w;
};
vector<edge> e;
int dis[M];

void bellman_ford(int n, vector<edge> e, int s)
{
    int sz = e.size(), i, j, f = 0;
    for(i = 0; i < n; i++){
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    for(i = 0; i < n-1; i++){
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
}
void solve()
{
    int n, m;
    int d[M];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d", &u, &v);
        u--, v--;
        w = pow(d[v]-d[u], 3);
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    bellman_ford(n, e, 0);

}
int main()
{
    int t, q;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){

        solve();
        printf("Case %d:\n", i);
        scanf("%d", &q);
        while(q--){
            int x;
            scanf("%d", &x);
            x--;
            if(dis[x] != INT_MAX && dis[x] > 2){
                printf("%d\n", dis[x]);
            }
            else{
                printf("?\n");
            }
        }
        e.clear();
    }

    return 0;
}

