// solved
#include<bits/stdc++.h>

using namespace std;
typedef long long lng;

const int MOD = 1e4 + 7;
const int MOD2 = MOD * MOD;

struct Matrix{
    vector<vector<int> > mat;
    int rows, cols;
    Matrix(){}
    Matrix(vector<vector<int> > values) : mat(values), rows(values.size()), cols(values[0].size()){}
    static Matrix identity_matrix(int n){
        vector<vector<int> > values(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
            values[i][i] = 1;
        return values;
    }
    Matrix operator*(const Matrix &other) const{
        int n = rows, m = other.cols;
        vector<vector<int> > result(rows, vector<int> (cols, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int tmp = 0;
                for(int k=0; k<cols; k++){
                    tmp += mat[i][k] * other.mat[k][j];
                    while(tmp >= MOD2){
                        tmp -= MOD2;
                    }
                }
                result[i][j] = tmp%MOD;
            }
        }
        return move(Matrix(move(result)));
    }
    inline bool is_square() const{
        return rows == cols;
    }
};

Matrix multiply(Matrix &m, Matrix &p, int n)
{
    while(n){
        if(n & 1)
            m = m * p;
        p = p * p;
        n >>= 1;
    }
    return m;
}

int main()
{
    int t, ts = 1;
    //cin >> t;
    scanf("%d", &t);
    while(t--){
        int n, a, b, c;
        //cin >> n >> a >> b >> c;
        scanf("%d%d%d%d", &n, &a, &b, &c);
        if(n<=2){
            //cout << "Case " << ts++ << ": " << 0 << endl;
            printf("Case %d: 0\n", ts++);
            continue;
        }
        Matrix M({{a, 0, b, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}}); // this is a square matrix
        Matrix MM({{a, 0, b, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}}); // this is a square matrix
        /*
            a, 0, b, 1      f2     f3
            1, 0, 0, 0   == f1  == f2
            0, 1, 0, 0   == f0  == f1
            0, 0, 0, 1      c      c
        */
        Matrix initial({{0}, {0}, {0}, {c}}); // this is a column matrix so represent this way
        M = multiply(M, MM, n-3) * initial;

        //cout << "Case " << ts++ << ": " << ans.mat[0][0]%MOD << endl;
        printf("Case %d: %d\n", ts++, M.mat[0][0]);
    }

    return 0;
}



