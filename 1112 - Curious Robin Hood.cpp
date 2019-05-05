#include <bits/stdc++.h>

using namespace std;
#define MX 1000001
typedef long long int ll;
int ara[MX];
int tree[3*MX];

void built_tree(int node, int a, int b)
{
    if (a>b)
        return;

    if (a==b){
        tree[node]=ara[a];
        return;
    }
    int left=node*2+1;
    int right=node*2+2;
    int mid=(a+b)/2;
    built_tree(left, a, mid);
    built_tree(right, mid+1, b);
    tree[node]=tree[left]+tree[right];

}
void update_tree(int node, int a, int b, int i, int newvalue)
{
    if (i>b || i<a || a>b)
        return;
    if (a==b){
        tree[node]+=newvalue;
        return;
    }

    int left=node*2+1;
    int right=node*2+2;
    int mid=(a+b)/2;
    update_tree(left, a, mid, i, newvalue);
    update_tree(right, mid+1, b, i, newvalue);
    tree[node]=tree[left]+tree[right];
}

int query (int node, int a, int b, int i, int j)
{
    if (i>b || j<a || a>b)
        return 0;
    if (a>=i && b<=j)
        return tree[node];

    int left=node*2+1;
    int right=node*2+2;
    int mid=(a+b)/2;
    int p1=query(left, a, mid, i, j);
    int p2=query(right, mid+1, b, i, j);
    return p1+p2;
}

int main ()
{
    ll T, n, q, i, j, v, a, ck, mx, c=1;
    scanf ("%lld", &T);
    while (T--){
        scanf ("%lld%lld",&n, &q);
        for (a=0; a<n; a++){
            scanf ("%lld", &ara[a]);
        }
        built_tree(0, 0, n-1);
        printf ("Case %lld:\n", c++);
        for (a=0; a<q; a++){
            scanf ("%lld", &ck);
            if (ck==1){
                scanf ("%lld", &i);
                mx=query(0, 0, n-1, i, i);
                update_tree(0, 0, n-1, i, -mx);
                printf ("%lld\n", mx);
            }
            else if (ck==2){
                scanf ("%lld%lld", &i, &v);
                update_tree(0, 0, n-1, i, v);
            }
            else {
                scanf("%lld%lld", &i, &j);
                mx=query(0, 0, n-1, i, j);
                printf ("%lld\n", mx);
            }
        }
    }
    return 0;
}

