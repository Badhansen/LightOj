// Full Ok code
// Light-oj 1067 Combination
// Solved
#include <cstdio>

void factorial (void);
struct inverse extended_gcd(long long a,long long b);

struct inverse
{
    long long x,y;
} inv;

int fact[1000020];

int main ()
{
    int kase, count=0;
    int n,k,answer;

    scanf("%d",&kase);

    factorial ();

    while (kase--)
    {
        scanf("%d %d",&n,&k);
        answer=((long long)fact[k]*(long long)fact[n-k])%1000003;
        if (fact[n]%answer==0)
            answer=fact[n]/answer;
        else
        {
            inv=extended_gcd(answer,1000003);
            if (inv.x<0)
            {
                inv.x+=1000003;
            }
            answer=((long long)fact[n]*inv.x)%1000003;
        }

        printf("Case %d: %d\n",++count,answer);
    }
    return 0;
}

void factorial (void)
{
    int i,j,temp=1;

    fact[0]=1;
    for (i=1; i<=1000000; i++)
    {
        fact[i]=((long long)fact[i-1]*(long long)i)%1000003;
    }
}

struct inverse extended_gcd(long long a,long long b)
{
    struct inverse temp;
    long long temp1,temp2;
    if (a%b==0)
    {
        temp.x=0;
        temp.y=1;
        return (temp);
    }
    else
    {
        temp = extended_gcd(b, a%b);
        temp1=temp.x;
        temp2=temp.y;
        temp.x=temp2;
        temp.y=temp1-(temp2*(a/b));
        return (temp);
    }
}
