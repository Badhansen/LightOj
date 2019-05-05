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

int x[]={+0, +0, +1, -1};
int y[]={+1, -1, +0, +0};





/*

    MY code start here
    Solved

*/



#define M 100001
i64 ara[M];
i64 tree[4*M];
i64 lazy[4*M];
void built_tree(i64 id, i64 a, i64 b)
{

    if (a==b)
    {
        tree[a]=ara[a];
        return;
    }
    i64 l=2*id;
    i64 r=l+1;
    i64 m=(a+b)/2;
    built_tree(l, a, m);
    built_tree(r, m+1, b);
    tree[id]=tree[l]+tree[r];
}
void update_tree(i64 id, i64 a, i64 b, i64 i, i64 j, i64 val)
{

    if(i>b || j<a) return;
    if (a>=i && b<=j)
    {
        tree[id]+=(b-a+1)*val;
        lazy[id]+=val;
        return;

    }



    i64 l=2*id;
    i64 r=l+1;
    i64 m=(a+b)/2;

    if (lazy[id])
    {
        tree[l]+=(m-a+1)*lazy[id];
        tree[r]+=(b-m)*lazy[id];
        if (a!=b){
            lazy[l]+=lazy[id];
            lazy[r]+=lazy[id];
        }

        lazy[id]=0;

    }

    update_tree(l, a, m, i, j, val);
    update_tree(r, m+1, b, i, j, val);
    tree[id]=tree[l]+tree[r];

}
i64 query_tree(i64 id, i64 a, i64 b, i64 i, i64 j)
{

    if (i>b || j<a) return 0;

    if (a>=i && b<=j)
        return tree[id];
    i64 l=2*id;
    i64 r=l+1;
    i64 m=(a+b)/2;
    if (lazy[id])
    {
        tree[l]+=(m-a+1)*lazy[id];
        tree[r]+=(b-m)*lazy[id];
        if (a!=b){
            lazy[l]+=lazy[id];
            lazy[r]+=lazy[id];
        }
        lazy[id]=0;
    }
    return query_tree(l, a, m, i, j)+query_tree(r, m+1, b, i, j);
}

int main ()
{
    i64 t, n, q, i, c=1;
    scanf("%lld", &t);
    while (t--){
        scanf("%lld%lld", &n, &q);

        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        printf ("Case %lld:\n", c++);
        for (i=0; i<q; i++){
            i64 x;
            scanf("%lld", &x);
            if (x==0){
                i64 a, b, v;
                scanf("%lld%lld%lld", &a, &b, &v);
                update_tree(1, 0, n-1, a, b, v);
            }
            else {
                i64 a, b;
                scanf("%lld%lld", &a, &b);
                i64 ans=query_tree(1, 0, n-1, a, b);
                printf ("%lld\n", ans);
            }

        }
    }

    return 0;
}


