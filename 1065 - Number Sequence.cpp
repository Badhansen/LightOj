// SOLVED
#include<bits/stdc++.h>

using namespace std;
typedef long long lng;

const int MOD = 1e4; // for mod operator
const lng MOD2 = MOD * 1ll * MOD; // for using the mod trick
const int maxn = 2; // define the matrix size

struct Matrix
{
    int mat[maxn][maxn];
};

Matrix ans, base;
Matrix M_powers[55];

Matrix mul(Matrix &a, Matrix &b)
{
    Matrix ret;
    memset(ret.mat, 0, sizeof(ret.mat));
    for(int i=0; i<maxn; i++){
        for(int j=0; j<maxn; j++){
            lng t = 0;
            for(int k=0; k<maxn; k++){
                t +=  (a.mat[i][k] * 1ll * b.mat[k][j]);
                while(t >= MOD2){
                    t -= MOD2;
                }
            }
            ret.mat[i][j] = t%MOD;
        }
    }
    return ret;
}
void pre_cal()
{
    M_powers[0] = base;
    for(int i=1; i<55; i++){
        M_powers[i] = mul(M_powers[i-1], M_powers[i-1]);
    }
}
void fast_expo(int n)
{
    int p = 0;
    while(n){
        if(n & 1){
            ans = mul(ans, M_powers[p]);
        }
        p++;
        n >>= 1;
    }
}
void MatPow(int n)
{
    if(n < 3) return;
    while(n){
        if(n & 1){
            ans = mul(ans, base);
        }
        base = mul(base, base);
        n >>= 1;
    }
}

int main()
{
    int t, ts = 1, n, a, b, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &a, &b, &n, &m);
        if(n < 2){
            int x = n == 1 ? b : a;
            printf("Case %d: %d\n", ts++, x);
            continue;
        }
        memset(base.mat, 0, sizeof(base.mat));
        base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
        memset(ans.mat, 0, sizeof(ans.mat));
        for(int i=0; i<maxn; ++i) ans.mat[i][i] = 1;
        MatPow(n-1);
        int p = pow(10, m);
        int Ans = (ans.mat[0][0]*b + ans.mat[0][1]*a)%p;
        printf("Case %d: %d\n", ts++, Ans);
    }

    return 0;
}


