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
    All thanks to rafi kamal vaiya
*/
/*
    Algorithm: BFS/DFS
    This is a simple problem. Look at the first test case. You have to find the shortest path
    from A to B (using BFS or DFS). Then you have to find the shortest path from B to C. And
    then C to D and D to E. The result is the sum of all these paths.
    There is only one thing you need to keep in mind. According to the problem description,
    "if he lands on a particular food he must collect it" and
    "For some superstitious reason, Yogi decides to collect all the foods in order"
    So, say you are finding the shortest path from C to D. Then you can't pass over E or any
    character greater than E, otherwise you will break the order. But you can certainly pass
    over A or B.
*/

int n, t, test = 1;
bool vis[12][12];
string str[12];
char s, l;

struct Point
{
    int x, y, t;
	Point(int x, int y, int time)
	{
	    this->x = x;
	    this->y = y;
	    this->t = time;
    }
	Point(){}
};
bool NOT(int x, int y)
{
    if(x < 0 or x >= n or y < 0 or y >= n)
        return true;
    return false;
}
int bfs(Point a, char s)
{
    if(s == l)
        return a.t;
    memset(vis, false, sizeof vis);
    vis[a.x][a.y] = true;
    queue<Point> Q;
    Q.push(a);
    while(!Q.empty())
    {
        Point n = Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int a, b;
            a = n.x + x[i];
            b = n.y + y[i];

            if(NOT(a, b)) continue;

            if(str[a][b] == s+1)
            {
               return bfs(Point(a, b, n.t+1), s+1);
            }
            else if(!vis[a][b] and (str[a][b] == '.' or (isalpha(str[a][b]) and str[a][b] <= s)))
            {
                Q.push(Point(a, b, n.t+1));
                vis[a][b] = true;
            }
        }
    }
    return -1;
}
void solve()
{
    Point point;
    s = 'A', l = 'A';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(str[i][j]=='A')
            {
                point = Point(i, j, 0);

            }
            if(isalpha(str[i][j]))
            {
                l = max(l, str[i][j]);
            }

        }
    }
    int r = bfs(point, s);
    if(r >= 0){
        printf("Case %d: %d\n", test++, r);
    }
    else{
        printf("Case %d: Impossible\n", test++);
    }
}
int main ()
{
    filein();
    fileout();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cin.ignore();
        for(int i=0; i<n; i++){
            cin >> str[i];
        }
        solve();
    }
    return 0;
}




