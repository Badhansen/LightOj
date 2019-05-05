#include<cstdio>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<limits>


using namespace std;


#define filein()       freopen("in.txt", "r", stdin)
#define fileout()      freopen("out.txt", "w", stdout)

#define FIO()          ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


#define all(x)         x.begin(), x.end()
#define nfound(v, n)   find(all(v), n)==v.end()
#define found(v, n)    find(all(v), n)!=v.end()
#define UB(v, n)       upper_bound(all(v), n)-v.begin()
#define LB(v, n)       lower_bound(all(v), n)-v.begin()


#define on(n, p)       (n | (1<<(p)))
#define off(n, p)      (n & ~(1<<(p)))
#define check(n, p)    (bool)(n & (1<<(p)))


#define MS(x, v)       memset(&x, v, sizeof(x))
#define CL(x)          memset(&x, 0, sizeof(x))
#define mp             make_pair
#define pb             push_back
#define p              push
#define sz             size
#define cl             clear
#define po             pop
#define em             emplty
#define ss             second
#define fi             first

#define sf             scanf
#define pf             printf
#define pf1(n)         pf("%d", n)
#define sc1(n)         sf("%d", &n)
#define scl1(n)        sf("%I64d", &n)
#define sc2(n, m)      sf("%d %d", &n, &m)
#define scl2(n, m)     sf("%I64d %I64d", &n, &m)
#define sc3(n, m, v)   sf("%d %d %d", &n, &m, &v)
#define scl3(n, m, v)  sf("%I64d %I64d %I64d", &n, &m, &v)
#define nl()           pf("\n")
#define endl           '\n'


#define Max(x, y)      ((x)>(y) ? (x) : (y))
#define Min(x, y)      ((x)<(y) ? (x) : (y))
#define Abs(x)         ((x)<0 ? (-(x)): (x))


#define PI             acos(-1.0)
#define EPS            1e-9


#define MAX            2e18
#define MOD            1000000007


typedef long long lng;
typedef unsigned long long ulng;
typedef pair<int, int> pii;
typedef pair<lng, lng> pll;
typedef vector<int> vi;
typedef vector<lng> vl;


template<class T> inline void IO(T &x){char c=getchar();T sgn=1;while(c<'0' || c>'9'){if (c=='-') sgn=-1;c=getchar();}x=0;while(c>='0' && c<='9'){x=(T)(x<<1)+(x<<3)+c-'0';c=getchar();}x*=sgn;}
template<class T> T POW(T b, T p){T res=1;while(p>0){if (p&1) res*=b;p >>= (1ll), b*=b;}return res;}
template<class T> T bMOD(T a, T p, T m){if (p==0) return (T) 1;if (!(p&1)){T temp=bMOD(a, p/2, m);return ((temp%m)*(temp%m))%m;}return ((a%m)*(bMOD(a, p-1, m)%m))%m;}
template<class T> T inMOD(T a, T m){return bMOD(a, m-2, m);}
template<class T> bool isPrime(T n){for(T i=2; i*i<=n; i++){if (n%i==0) return false;}return true;}
template<class T> string toString(T n){stringstream ss;string num;ss<<n;ss>>num;return num;}
template<class T> T sq(T n){return (n*n);}
template<class T> T gcd(T a, T b){return (b==0) ? a : gcd (b, a%b);}
template<class T> T lcm(T a, T b){return (a/gcd (a, b))*b;}
bool iseq(double a, double b){return fabs(a-b)<EPS;}
template<class T> T toDeg(T x){return (180.0*x)/((T)PI);}
template<class T> T toReg(T x){return (x*(T)PI)/(180.0);}
template<class T> double _distance (T x1, T y1, T x2, T y2){return 1.0*sqrt(sq(x1-x2)+sq(y1-y2));}

int kx[]={-2, -2, +2, +2, +1, -1, +1, -1};
int ky[]={+1, -1, +1, -1, -2, -2, +2, +2};

int dx[]={+0, +0, -1, +1, +1, +1, -1, -1};
int dy[]={+1, -1, +0, +0, -1, +1, +1, -1};


int x[]={+0, +0, +1, -1};
int y[]={+1, -1, +0, +0};



/*

    @author: Badhan Sen
    CSE-14, JUST.
    mail: galaxybd9@gmail.com
    Solved
*/

string str[21];
bool visited[21][21];
int dis[21][21];
int row, column;
bool flag = false;
bool inline valid(int nx, int ny)
{
    if (nx>0 && nx<row-1 && ny>0 && ny<column-1 && str[nx][ny] != 'm' && str[nx][ny] != '#' && visited[nx][ny]==false){
        return true;
    }
    return false;
}
int bfs(int r, int c, int rd, int cd)
{

    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c]=true;
    dis[r][c]=0;
    while (!q.empty()){
        pair<int, int> node;
        node=q.front();
        q.pop();
        if (node.first==rd && node.second==cd){
            flag = true;
            return dis[rd][cd];
        }
        for (int i=0; i<4; i++){
            int nx, ny;
            nx=node.first+x[i];
            ny=node.second+y[i];
            if (valid(nx, ny)){
                visited[nx][ny]=true;
                dis[nx][ny]=dis[node.first][node.second]+1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}


int main()
{
    filein();
    fileout();
    int t, ts = 1;
    cin >> t;
    while(t--){
        cin >> row >> column;
        pair<int, int> a, b, c, d;

        for(int i = 0; i < row; i++){
            cin >> str[i];
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(str[i][j] == 'a'){
                    a.first = i;
                    a.second = j;
                }
                if(str[i][j] == 'b'){
                    b.first = i;
                    b.second = j;
                }
                if(str[i][j] == 'c'){
                    c.first = i;
                    c.second = j;
                }
                if(str[i][j] == 'h'){
                    d.first = i;
                    d.second = j;
                }
            }
        }
        memset(visited, false, sizeof visited);
        memset(dis, 0, sizeof dis);
        int ans = bfs(a.first, a.second, d.first, d.second);
        memset(visited, false, sizeof visited);
        memset(dis, 0, sizeof dis);
        ans = max(ans, bfs(b.first, b.second, d.first, d.second));
        memset(visited, false, sizeof visited);
        memset(dis, 0, sizeof dis);
        ans = max(ans, bfs(c.first, c.second, d.first, d.second));

        cout << "Case " << ts++ << ": " << ans << endl;
    }


    return 0;
}
