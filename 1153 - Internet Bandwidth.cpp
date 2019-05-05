// Solved
#include<bits/stdc++.h>

using namespace std;
#define V 101
#define INF 10000000

int res[V][V], mf, f, s, t, c, n;
vector<int> g[V];
vector<int> p;

void augment(int v, int minEdge)
{
    if(v==s){
        f=minEdge;
        return;
    }
    else if(p[v]!=-1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v]-=f;
        res[v][p[v]]+=f;
    }
}
int EdmondsKarp()
{
    mf=0;
    while(1){
        f=0;
        bitset<V> visited;
        visited[s]=true;
        p.assign(V, -1);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0; i<g[u].size(); i++){
                int v=g[u][i];
                if(res[u][v]>0 && !visited[v]){
                    q.push(v);
                    p[v]=u;
                    visited[v]=true;
                }
            }
        }
        augment(t, INF);
        if(f==0)
            break;
        mf+=f;
    }
    return mf;
}
int main()
{
    int ts=1, test;
    scanf("%d", &test);
    while(ts<=test){
        for(int i=0; i<V; i++){
            g[i].clear();
        }
        scanf("%d", &n);
        scanf("%d%d%d", &s, &t, &c);
        memset(res, 0, sizeof res);
        for(int i=0; i<c; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back(v);
            g[v].push_back(u);
            res[u][v]+=w;
            res[v][u]+=w;
        }
        printf("Case %d: %d\n", ts++, EdmondsKarp());

    }

    return 0;
}
