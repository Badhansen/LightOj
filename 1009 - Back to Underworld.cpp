// solved
#include<bits/stdc++.h>

using namespace std;
#define MM 20001

int visited[MM];
vector <int> graph[MM];

enum {
    NOT_VISITED, vampires, lykans

};

int bfs (int source)
{
    for (int i=1; i<=MM; i++) visited[i]=NOT_VISITED;
    int mx=0;
    for (int a=1; a<MM; a++){
        if (!graph[a].empty() && visited[a]==NOT_VISITED){
            queue <int> Q;
            int ly=0, vm=0; // count the vampires and lykans
            Q.push(a);
            visited[a]=vampires;
            vm++;
            while (!Q.empty()){
                int top=Q.front();
                Q.pop();
                for (int i=0; i<graph[top].size(); i++){
                    int v=graph[top][i];
                    if (visited[v]==NOT_VISITED){

                        if (visited[top]==vampires){
                            visited[v]=lykans;

                            ly++; // increasing the counter

                        }
                        else {
                            visited[v]=vampires;

                            vm++; // increasing the counter
                        }

                        Q.push(v);

                    }
                }
            }

            mx+=max(ly, vm);

        }

    }
    return mx;

}

int main ()
{

    int T, c=1;
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        for (int j=0; j<MM; j++){
            graph[j].clear();
        }
        int n, start;
        scanf("%d", &n);
        for (int k=0; k<n; k++){
            int u, v;

            scanf("%d%d", &u, &v);
            if (k==0) start=u;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans;
        ans=bfs(start);
        printf ("Case %d: %d\n", c++, ans);
    }
    return 0;
}
