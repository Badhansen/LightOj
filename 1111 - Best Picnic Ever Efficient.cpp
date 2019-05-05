// Solved by Only one bfs
#include<bits/stdc++.h>

using namespace std;
#define MM 1001
vector<int> edge[MM];
int cnt[MM] = {0};
bool visited[MM][101];
queue<pair<int, int> > Q;

int main()
{
    filein();
    fileout();
    int t, ts = 1;
    cin >> t;
    while(ts <= t){
        for(int i=0; i<MM; i++){
            edge[i].clear();
            cnt[i] = 0;
        }
        int n, k, m;
        cin >> k >> n >> m;
        int p[MM];
        memset(visited, false, sizeof visited);
        for(int i=1; i<=k; i++){
            cin >> p[i];
            Q.push({p[i], i});
            visited[p[i]][i] = true;
        }
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
        }
        while(!Q.empty()){
            pair<int, int> u = Q.front();
            Q.pop();
            cnt[u.first]++;
            vector<int> :: iterator i;
            for(i=edge[u.first].begin(); i!=edge[u.first].end(); i++){
                int node = *i;
                if(visited[node][u.second] == false){
                    visited[node][u.second] = true;
                    Q.push({node, u.second});
                }
            }
        }
        int count_city = 0;
        for(int i=1; i<=n; i++){
            if(cnt[i] >= k) count_city++;
        }
        cout <<"Case " << ts++ << ": " << count_city << endl;
    }
    return 0;
}

