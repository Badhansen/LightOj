// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 100001


struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
int pr[MM];
vector<edge> e;
vector<pair<int, int> > g[505];
int dis[505];
int n;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
    //return (pr[r] == r) ? r : _find(pr[r]);
}
void kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=0; i<n; i++)
        pr[i]=i;

    int count=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v){
            g[e[i].u].push_back(make_pair(e[i].v, e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u, e[i].w));
            pr[u]=v;
            count++;
            if (count==n-1)
                break;
        }
    }
}
void bfs(int n, int s)
{
    bool vis[505];
    memset(vis, false, sizeof vis);
    memset(dis, -1, sizeof dis);
    dis[s]=0;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++){
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(!vis[v]){
                dis[v]=max(dis[u], w);
                q.push(v);
                vis[v]=true;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dis[i]==-1){
            cout << "Impossible" << endl;
        }
        else
            cout << dis[i] << endl;
    }

}
int main()
{
    int test, t=1;
    scanf("%d", &test);
    while(t<=test){
        for(int i=0; i<501; i++){
            g[i].clear();
        }
        e.clear();
        int m, s;
        scanf("%d%d", &n, &m);

        for(int i=0; i<m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge get;
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);

        }
        scanf("%d", &s);
        printf("Case %d:\n", t++);
        kruskal(n);
//        vector<pair<int, int> > :: iterator i;
//
//        for(int i=0; i<n; i++){
//                cout << "u = " << i;
//            for(int j=0; j<g[i].size(); j++){
//                cout <<" v = " << g[i][j].first << " w = " << g[i][j]. second << endl;
//            }
//        }
        bfs(n, s);

    }

    return 0;
}

