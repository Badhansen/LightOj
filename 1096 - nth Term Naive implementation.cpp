// Solved
#include<bits/stdc++.h>

using namespace std;

const int mod = 1e4 + 7;
const int mod2 = mod * mod;

struct Matrix{
    int _size;
    int n[4][4];
};

Matrix multiply(Matrix &m, Matrix &q)
{
    Matrix res;
    res._size = m._size;
    for(int i=0; i<m._size; i++){
        for(int j=0; j<m._size; j++){
            int t = 0;
            for(int k=0; k<q._size; k++){
                t += m.n[i][k] * q.n[k][j];
                while(t >= mod2){
                    t -= mod2;
                }
            }
            res.n[i][j] = t%mod;
        }
    }
    return res;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ts = 1;
    scanf("%d", &t);
    while(t--){
        int n, a, b, c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        if(n<=2){
            printf("Case %d: 0\n", ts++);
            continue;
        }
        Matrix ans;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                ans.n[i][j] = 0;
            }
        }
        ans._size = 4;
        ans.n[0][0] = a;
        ans.n[0][2] = b;
        ans.n[0][3] = 1;
        ans.n[1][0] = 1;
        ans.n[2][1] = 1;
        ans.n[3][3] = 1;
        Matrix pq;
        pq._size = 4;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                pq.n[i][j] = 0;
            }
        }
        pq.n[0][0] = a;
        pq.n[0][2] = b;
        pq.n[0][3] = 1;
        pq.n[1][0] = 1;
        pq.n[2][1] = 1;
        pq.n[3][3] = 1;
        /*
            a, 0, b, 1      f2     f3
            1, 0, 0, 0   == f1  == f2
            0, 1, 0, 0   == f0  == f1
            0, 0, 0, 1      c      c
        */
        n -= 3;
        while(n){
            if(n & 1){
                ans = multiply(ans, pq);
            }
            pq = multiply(pq, pq);
            n >>= 1;
        }
        printf("Case %d: %d\n", ts++, (ans.n[0][3]*c)%mod);
    }

    return 0;
}
