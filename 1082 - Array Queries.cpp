#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
#define M 100001
int ara[M];
int tree[3*M];

void built_tree(int node, int a, int b)
{
    if (a==b){
       tree[node]=ara[a];
       return;
    }
    int left, right, mid;
    left=2*node;
    right=2*node+1;
    mid=(a+b)/2;
    built_tree(left, a, mid);
    built_tree(right, mid+1, b);
    tree[node]=min (tree[left], tree[right]);
}
int query (int node, int a, int b, int i, int j)
{
    if (i>b || j<a || a>b)
        return M;
    if (a>=i && b<=j)
        return tree[node];

    int left, right, mid;

    left=2*node;
    right=2*node+1;
    mid=(a+b)/2;
    int p1, p2, res;

    p1=query(left, a, mid, i, j);
    p2=query(right, mid+1, b, i, j);
    res=min (p1, p2);
    return res;
}
int main ()
{
    ll T, n, q, i, j, a, c=1, mx;
    scanf ("%lld", &T);
    while (T--){
        scanf ("%lld%lld", &n, &q);
        for (a=1; a<=n; a++){
            scanf ("%lld", &ara[a]);
        }
        built_tree(1, 1, n);
        printf ("Case %lld:\n", c++);
        for (a=1; a<=q; a++){
            scanf ("%lld%lld", &i, &j);
            mx=query(1, 1, n, i, j);
            printf ("%lld\n", mx);
        }
    }
    return 0;
}
