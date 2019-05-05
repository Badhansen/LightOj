// Solved
#include<bits/stdc++.h>

using namespace std;
#define V 58
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
        scanf("%d%d", &n, &m);
        memset(res, 0, sizeof res);

        // Here source is 0
        // Sink is 57
        //  Contestants is 1 to m
        // t-shirt is 51 to 56
        // now creating the graph

        map<string, int> mp;

        // t-shirt indexing
        mp["XXL"]=51;
        mp["XL"]=52;
        mp["L"]=53;
        mp["M"]=54;
        mp["S"]=55;
        mp["XS"]=56;

        for(int i=1; i<=m; i++){
            string a, b;
            cin >> a >> b;
            g[i].push_back(mp[a]);
            g[mp[a]].push_back(i);
            g[i].push_back(mp[b]);
            g[mp[b]].push_back(i);
            res[i][mp[a]]=1;
            res[i][mp[b]]=1;
        }

        // the source 0 and the sink is 57
        //connecting the source and sink
        s=0, t=57;
        // source connection
        for(int i=1; i<=m; i++){
            g[s].push_back(i);
            g[i].push_back(s);
            res[s][i]=1;
        }

        // sink connection
        for(int i=51; i<=56; i++){
            g[i].push_back(t);
            g[t].push_back(i);
            res[i][t]=n; // the n color has 6 different t-shirt
        }
        if(EdmondsKarp()==m)
            printf("Case %d: YES\n", ts++);

        else
            printf("Case %d: NO\n", ts++);
    }

    return 0;
}
