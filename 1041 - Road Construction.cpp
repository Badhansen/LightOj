// solved
#include<bits/stdc++.h>

using namespace std;

#define MM 1000001


struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
int pr[MM];
vector<edge> e;
map<string, int> m;

int _find(int r)
{
    if(pr[r]==r) return r;
    return _find(pr[r]);
    //return (pr[r] == r) ? r : _find(pr[r]);
}
void kruskal(int n)
{
    sort(e.begin(), e.end());
    for (int i=1; i<=n; i++)
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
            if (count==n-1)
                break;
        }
    }
    if(count==n-1){
        cout << s << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int N, M, t=1, test;
    scanf("%d", &test);
    while(t<=test){
        scanf("%d", &M);
        int city=0;
        m.clear();
        cin.ignore();
        for(int i=0; i<M; i++){
            string a, b;
            int w;
            cin >> a >> b >> w;
            if(m.find(a)==m.end()){
                m[a]=++city;
            }
            if(m.find(b)==m.end()){
                m[b]=++city;
            }
            edge get;
            get.u=m[a];
            get.v=m[b];
            get.w=w;
            e.push_back(get);
        }
        N=city;
        cout << "Case " << t << ": ";
        kruskal(N);
        t++;
        e.clear();
    }
    return 0;
}

