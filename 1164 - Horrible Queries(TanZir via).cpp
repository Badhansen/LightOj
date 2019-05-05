/*
The Great Template of Salazar Slytherin
*/
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb  push_back
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

/// Tanzir
#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define DBG         printf("Hi\n")
#define PI          acos(-1.00)
#define xx          first
#define yy          second

typedef double db;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;
typedef pair <long long , long long > pll;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


// Range_update_Range_query_BIT
// An array, suppose arr[MAX]
// 1 based indexing
// mxIdx is the highest index
// If you want only single point update, use only BIT_ADD and the first two functions

#define MAX         100000
LL BIT_ADD[MAX+10];
LL BIT_SUB[MAX+10];
int mxIdx;

void init()
{
    mem(BIT_ADD, 0);
    mem(BIT_SUB, 0);
}

void update(LL BIT[], int idx, LL val) //single point update, arr[idx] = val
{
    while(idx <= mxIdx)
        BIT[idx] += val, idx += idx&-idx;
}

LL query(LL BIT[], int idx) // single point query, cumulative sum from arr[1] to arr[idx]
{
    LL ret = 0;
    while(idx)
        ret += BIT[idx], idx -= idx&-idx;
    return ret;
}


LL range_query(int L, int R) // cumulative sum from arr[L] to arr[R]
{
    LL ret = (R*query(BIT_ADD, R) - (L-1)*query(BIT_ADD, L-1)) - (query(BIT_SUB, R) - query(BIT_SUB, L-1)) ;
    return ret;
}

void range_update(int L, int R, LL v) // For i = L to R, arr[i] += val
{
    update(BIT_ADD, L,v);
    update(BIT_ADD, R+1, -v);
    update(BIT_SUB, L, v*(L-1));
    update(BIT_SUB, R+1, -v*(R));
}




int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int i, j, cs, t, n, q, type, v;
    sf(t);
    FRE(cs,1,t)
    {
        init();
        sff(n,q);
        mxIdx = n;
        printf("Case %d:\n",cs);
        while(q--)
        {
            sfff(type,i,j);
            i++;
            j++;
            if(type == 0)
            {
                sf(v);
                range_update(i,j,v);
            }
            else
            {
                printf("%lld\n", range_query(i,j));
            }
        }
    }
    return 0;
}
