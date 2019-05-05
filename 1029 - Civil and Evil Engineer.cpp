// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 101

struct edge {
    int u, v, w;
};

bool comsmall(edge const &a, edge const &b)
{
    return a.w<b.w;
}

bool combig(edge const &a, edge const &b)
{
    return a.w>b.w;
}

int pr[MM];
vector<edge> e;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
}
int kruskalsmall(int n)
{
    sort(e.begin(), e.end(), comsmall);
    for (int i=0; i<=n; i++)
        pr[i]=i;

    int count=0, s=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v) {
            pr[u]=v;
            count++;
            s+=e[i].w;
        }
    }
    return s;
}
int kruskalbig(int n)
{
    sort(e.begin(), e.end(), combig);
    for (int i=0; i<=n; i++)
        pr[i]=i;

    int count=0, s=0;
    int sz=e.size();
    for (int i=0; i<sz; i++) {
        int u=_find(e[i].u);
        int v=_find(e[i].v);
        if (u != v) {
            pr[u]=v;
            count++;
            s+=e[i].w;
        }
    }
    return s;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, t=1, test;
    scanf("%d", &test);
    while(t<=test){
        scanf("%d", &n);
        int u, v, w;
        while(1){
            scanf("%d%d%d", &u, &v, &w);
            if(!u && !v && !w) break;
            edge get;
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        int ans=kruskalsmall(n)+kruskalbig(n);
        if(ans%2==0){
            printf("Case %d: %d\n", t++, ans/2);
        }
        else{
            printf("Case %d: %d/2\n", t++, ans);
        }
        e.clear();
    }
    return 0;
}


