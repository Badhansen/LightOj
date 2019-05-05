// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 1000001

struct edge{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MM];
vector<edge> e;

int _find(int r)
{
    if(pr[r] == r)
        return r;
    return _find(pr[r]);
}
int kruskal(int n, int sum)
{
    sort(e.begin(), e.end());
    for(int i = 0; i < n; i++){
        pr[i] = i;
    }
    int cnt = 0, s = 0;
    int sz = e.size();
    bool flag = false;
    for(int i = 0; i < sz; i++){
        int u = _find(e[i].u);
        int v = _find(e[i].v);
        if(u != v){
            pr[u] = v;
            cnt++;
            s += e[i].w;
            if(cnt == n-1){
                flag = true;
                break;
            }
        }
    }
    if(flag || n == 1){
        return sum-s;
    }
    return -1;
}

void solve()
{
    int t, mat[51][51], n, ts = 1, sum;
    cin >> t;
    while(ts <= t){
        cin >> n;
        sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
                sum += mat[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    edge get;
                    get.u = i;
                    get.v = j;
                    get.w = mat[i][j];
                    e.push_back(get);
                }
            }
        }
        cout << "Case " << ts++ << ": " << kruskal(n, sum) << endl;
        e.clear();
    }
}
int main()
{
    solve();
}
