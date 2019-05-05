// Solved
#include<bits/stdc++.h>

using namespace std;

#define MM 100005

struct query{
    int l, r, id;
}q[MM];

const int k=320; // as sqrt(100000) is 320

bool cmp(const query &a, const query &b)
{
    int block_a=a.l/k, block_b=b.l/k;
    if(block_a==block_b)
        return a.r<b.r;
    return block_a<block_b;
}

int l=0, r=-1, sum=0, ans[MM], cnt[MM], a[MM];

void _add(int x)
{
    x=a[x];
    cnt[x]++;
    if(cnt[x]==1) sum++;
}
void _remove(int x)
{
    x=a[x];
    cnt[x]--;
    if(cnt[x]==0) sum--;
}
int main()
{
    int test, t=1, N, Q;
    scanf("%d", &test);
    while(t<=test){

        for(int i=0; i<MM; i++){
            cnt[i]=0;
            ans[i]=0;
        }

        scanf("%d%d", &N, &Q);

        for(int i=0; i<N; i++) scanf("%d", &a[i]);

        for(int i=0; i<Q; i++){
            cin >> q[i].l >> q[i].r;
            q[i].l--; q[i].r--;
            q[i].id=i;
        }

        sort(q, q+Q, cmp);

        l=0, r=-1, sum=0;

        for(int i=0; i<Q; i++){
            while(l>q[i].l) _add(--l);
            while(r<q[i].r) _add(++r);
            while(l<q[i].l) _remove(l++);
            while(r>q[i].r) _remove(r--);
            ans[q[i].id]=sum;
        }
        printf("Case %d:\n", t++);
        for(int i=0; i<Q; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

