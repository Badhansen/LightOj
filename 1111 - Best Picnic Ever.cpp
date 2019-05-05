// Solved with k bfs call
#include<bits/stdc++.h>

using namespace std;
#define MM 1001
vector<int> edge[MM];
int cnt[MM] = {0};
bool visited[MM];
int bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    cnt[s]++;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        vector<int> :: iterator i;
        for(i=edge[u].begin(); i!=edge[u].end(); i++){
            int v=*i;
            if(visited[v]==false){
                cnt[v]++;
                visited[v]=true;
                Q.push(v);
            }
        }
    }
}
int main()
{
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
        for(int i=1; i<=k; i++){
            cin >> p[i];
        }
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
        }
        for(int i=1; i<=k; i++){
            memset(visited, false, sizeof (visited));
            if(!visited[p[i]]){
                bfs(p[i]);
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
