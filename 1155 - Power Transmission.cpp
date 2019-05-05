// Solved
#include<bits/stdc++.h>

using namespace std;
#define V 202
#define INF 10000000

int res[V][V], mf, f, s, t, n, m;
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

        memset(res, 0, sizeof res);

        // Here source is 0 as Barisal
        // Sink is 201 as Dhaka
        // now creating the graph with vertex spilting technique
        // 1 vertex is spilting with 101 // 2 as 102 and so on

        for(int i=1; i<=n; i++){
            int w;
            scanf("%d", &w);
            g[i].push_back(100+i);
            g[100+i].push_back(i);
            res[i][100+i]=w;
        }

        scanf("%d", &m);

        // creating the graph
        for(int i=0; i<m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[100+u].push_back(v);
            g[v].push_back(100+u);
            res[100+u][v]=w;
        }
        int b, d;
        scanf("%d%d", &b, &d);

        // the source 0 as barisal and the sink is 201 as dhaka
        //connecting the source and sink

        // connect direct with 1, 2, 3 real node to Barisal as 0

        s=0, t=201;

        for(int i=0; i<b; i++){
            int u;
            scanf("%d", &u);
            g[s].push_back(u);
            g[u].push_back(s);
            res[s][u]=INF;
        }

        // connect direct with spilting edge to dhaka as 201
        for(int i=0; i<d; i++){
            int u;
            scanf("%d", &u);
            g[100+u].push_back(t);
            g[t].push_back(100+u);
            res[100+u][t]=INF;
        }
        int ans=EdmondsKarp();
        printf("Case %d: %d\n", ts++, ans);
    }

    return 0;
}

