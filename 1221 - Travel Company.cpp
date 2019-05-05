// Solved
#include<bits/stdc++.h>

using namespace std;
#define M 101

struct edge{
    int u, v;
    long long w;
};

vector<edge> e;
long long dis[M];

bool bellman_ford(int n, vector<edge> e)
{
    int sz = e.size(), i, j, f = 0;
    for(i = 0; i < n; i++){
        dis[i] = 0;
    }
    for(i = 0; i < n-1; i++){
        f = 0;
        for(j = 0; j < sz; j++){
            int u, v;
            long long w;
            u = e[j].u;
            v = e[j].v;
            w = dis[u]+e[j].w;
            if(w < dis[v]){
                dis[v] = w;
                f = 1;
            }
        }
        if(!f) break;
    }

    for(j = 0; j < sz; j++){
        int u, v;
        long long w;
        u = e[j].u;
        v = e[j].v;
        w = dis[u]+e[j].w;
        if(w < dis[v]){
            return true;
        }
    }
    return false;
}

int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(ts <= t){

        int n, r, p, I, E, s;
        scanf("%d%d%d", &n, &r, &p);
        for(int i = 0; i < r; i++){
            int u, v;
            scanf("%d%d%d%d", &u, &v, &I, &E);
            edge get;
            get.u = u;
            get.v = v;
            get.w = E*p-I;
            e.push_back(get);
        }

        printf("Case %d: ", ts++);

        if(bellman_ford(n, e)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        e.clear();
    }

    return 0;
}

