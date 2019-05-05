// Solved
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ipoint;

int x[]={+0, +0, +1, -1};
int y[]={+1, -1, +0, +0};

string matrix[501];
bool visited[501][501];
int d[501][501];
int row, column;
set<ipoint> path;
bool inline valid(int nx, int ny)
{
    if(nx >= 0 && nx< row && ny >= 0 && ny < column && matrix[nx][ny] != '#' && visited[nx][ny] == false){
        return true;
    }
    return false;
}
int bfs(int r, int c)
{
    path.clear();
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    path.insert({r, c});
    visited[r][c] = true;
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> node;
        node = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx, ny;
            nx=node.first+x[i];
            ny=node.second+y[i];
            if(valid(nx, ny)){
                visited[nx][ny] = true;
                if(matrix[nx][ny] == 'C') cnt++;
                path.insert({nx, ny});
                q.push(make_pair(nx, ny));
            }
        }
    }
    set<ipoint> :: iterator i;
    for(i=path.begin(); i!=path.end(); i++){
        ipoint n = *i;
        d[n.first][n.second] = cnt;
    }
    return cnt;
}
int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(t--){
        int Q;
        scanf("%d%d%d", &row, &column, &Q);
        for(int i=0; i<row; i++){
            cin >> matrix[i];
        }
        memset(visited, false, sizeof visited);
        memset(d, 0, sizeof d);
        printf("Case %d:\n", ts++);
        while(Q--){
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            if(!visited[x][y]){
                printf("%d\n", bfs(x, y));
            }
            else
                printf("%d\n", d[x][y]);


        }
    }
    return 0;
}
