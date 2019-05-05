// solved
#include<bits/stdc++.h>

using namespace std;

double x, y, c;

double call(double b)
{
    double u = sqrt(x * x - b * b) * sqrt(y * y - b * b);
    double d = sqrt(x * x - b * b) + sqrt(y * y - b * b);
    double res = u / d;
    return res;
}
int main()
{
    int t, ts = 1;
    cin >> t;
    while(t--){
        cin >> x >> y >> c;
        double low = 1, high = max(x, y);
        for(int i=0; i<1000; i++){
            double m = (low + high) / 2.00;
            if(call(m) > c){
                low = m;
            }
            else{
                high = m;
            }
        }
        cout << "Case " << ts++ << ": " << fixed << setprecision(10) << low << endl;
    }
    return 0;
}
