// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 10001

vector<int> g[MM];
set<pair<int, int> > ans;
int n;

void dfs(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time=0;
    low[u]=disc[u]=++time;
    visited[u]=true;

    vector<int> :: iterator i;
    for(i=g[u].begin(); i!=g[u].end(); i++){
        int v=*i;
        if(!visited[v]){

            parent[v]=u;
            dfs(v, visited, disc, low, parent);

            low[u]=min(low[u], low[v]);

            if(low[v]>disc[u]){
                if(u>v)
                    ans.insert(make_pair(v, u));
                else
                    ans.insert(make_pair(u, v));
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u], disc[v]);
        }
    }


}
void bridge()
{
    bool visited[n+10];
    int disc[n+10];
    int low[n+10];
    int parent[n+10];
    for(int i=0; i<n; i++){
        visited[i]=false;
        parent[i]=-1;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, visited, disc, low, parent);
        }
    }

    int sz=ans.size();
    printf("%d critical links\n", sz);
    set<pair<int, int> > :: iterator it;
    for(it=ans.begin(); it!=ans.end(); it++){
        cout << (*it).first << " - " << (*it).second << endl;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, i=1;
    scanf("%d", &test);
    while(i<=test){

        scanf("%d", &n);

        int j=0, h;
        for(h=0; h<MM; h++){
            g[h].clear();
        }
        ans.clear();

        while(j<n){
            int u, k, v;
            char l, r;
            scanf("%d %c%d%c ", &u, &l, &k, &r);

            for(h=0; h<k; h++){
                scanf("%d", &v);
                g[u].push_back(v);
            }
            j++;
        }
        printf("Case %d:\n", i++);
        bridge();
    }

    return 0;
}
