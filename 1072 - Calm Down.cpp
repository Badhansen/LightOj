// Solved
#include<bits/stdc++.h>


using namespace std;


#define PI             acos(-1.0)

int main ()
{

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        double R;
        int n;
        cin >> R >> n;
        double r = (R * sin(PI / n)) / (1.00 + sin(PI / n));
        cout << "Case " << (i+1) << ": " << fixed << setprecision(10) << r << endl;
    }


    return 0;
}
