#include<bits/stdc++.h>


using namespace std;


#define FIO()          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x)         x.begin(), x.end()


#define Max(x, y)      ((x)>(y) ? (x) : (y))
#define Min(x, y)      ((x)<(y) ? (x) : (y))
#define Abs(x)         ((x)<0 ? (-(x)): (x))


#define PI             acos(-1.0)
#define EPS            1e-9


#define MAX            2e18
#define MOD            1000000007


typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int, int> pii;
typedef pair<i64, i64> pll;
typedef vector<int> vi;
typedef vector<i64> vl;


template<class T> T POW (T b, T p){T res=1;while(p>0){if (p&1) res*=b;p >>= (1ll), b*=b;}return res;}
template<class T> T bMOD (T a, T p, T m){ if (p==0) return (T) 1;if (!(p&1)){T temp=bMOD(a, p/2, m);return ((temp%m)*(temp%m))%m;}return ((a%m)*(bMOD(a, p-1, m)%m))%m;}
template<class T> T inMOD (T a, T m){return bMOD (a, m-2, m);}
template<class T> bool isPrime (T n){ for (T i=2; i*i<=n; i++){if (n%i==0) return false;}return true;}
template<class T> string toString (T n){ stringstream ss;string num;ss<<n;ss>>num;return num;}
template<class T> T sq (T n){ return (n*n);}
template<class T> T gcd (T a, T b){ return (b==0) ? a : gcd (b, a%b);}
template<class T> T lcm (T a, T b){ return (a/gcd (a, b))*b;}
bool iseq (double a, double b){ return fabs(a-b)<EPS;}
template<class T> T toDeg (T x){ return (180.0*x)/((T)PI);}
template<class T> T toReg (T x){ return (x*(T)PI)/(180.0);}
template<class T> double _distance (T x1, T y1, T x2, T y2){ return 1.0*sqrt(sq(x1-x2)+sq(y1-y2));}

int kx[]={-2, -2, +2, +2, +1, -1, +1, -1};
int ky[]={+1, -1, +1, -1, -2, -2, +2, +2};

int dx[]={+0, +0, -1, +1, +1, +1, -1, -1};
int dy[]={+1, -1, +0, +0, -1, +1, +1, -1};






/*

    MY code start here
    Solved

*/
#define x 30001

vector<pair<int, int> > graph[x];
vector<pair<int, int> > :: iterator it;
bool visited[x];
i64 weight[x];

void dfs (int source, int cost)
{
    visited[source]=true;
    weight[source]=cost;
    for (int i=0; i<graph[source].size(); i++){
        int node, w;
        node=graph[source][i].first;
        w=graph[source][i].second;
        if (!visited[node]){

            dfs(node, cost+w);
        }

    }
}


int main ()
{
    int t, n, c=1;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf("%d", &n);
        for (int j=0; j<n; j++){
            graph[j].clear();
            weight[j]=0;
            visited[j]=false;
        }
        for (int j=0; j<n-1; j++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        dfs(0, 0);
        int max_distance=-1, farthest_node;

        for (int j=0; j<n; j++){
            if (max_distance<weight[j]){
                max_distance=weight[j];
                farthest_node=j;
            }
        }
        for (int j=0; j<n; j++){
            weight[j]=0;
            visited[j]=false;
        }

        dfs(farthest_node, 0);
        int ans=*max_element(weight, weight+n);
        printf ("Case %d: %d\n", c++, ans);
    }

    return 0;
}



