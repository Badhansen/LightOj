// Solved
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
Matrix M_powers[50];
void pre_cal(Matrix M)
{
    assert(M.is_square()); // for stopping the execution
    M_powers[0] = M;
    for(int i=1; i<50; i++){
        M_powers[i] = M_powers[i-1] * M_powers[i-1];
    }
}
Matrix fast_expo(int n)
{
    Matrix result = Matrix :: identity_matrix(M_powers[0].mat.size());
    int p = 0;
    while(n){
        if(n & 1)
            result = result * M_powers[p];
        p++;
        n >>= 1;
    }
    return result;
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
        /*
            a, 0, b, 1      f2     f3
            1, 0, 0, 0   == f1  == f2
            0, 1, 0, 0   == f0  == f1
            0, 0, 0, 1      c      c
        */
        pre_cal(M);
        Matrix initial({{0}, {0}, {0}, {c}}); // this is a column matrix so represent this way
        Matrix ans = fast_expo(n-2) * initial;

        //cout << "Case " << ts++ << ": " << ans.mat[0][0]%MOD << endl;
        printf("Case %d: %d\n", ts++, ans.mat[0][0]);
    }

    return 0;
}


