#include <bits/stdc++.h>

using namespace std;
int ara[101];
void swap_value (int i, int j)
{
    int temp;
    temp=ara[i];
    ara[i]=ara[j];
    ara[j]=temp;
}
void mult_value (int x, int n)
{
    for (int i=0; i<n; i++){
        ara[i]=ara[i]*x;
    }
}
void add_value (int x, int n)
{
    for (int i=0; i<n; i++){
        ara[i]=ara[i]+x;
    }
}
void div_value (int x, int n)
{
    for (int i=0; i<n; i++){
        ara[i]=ara[i]/x;
    }
}
int main ()
{
    string s;
    int T, n, m, c=1;
    cin >> T;
    while (T--){
        cin >> n >> m;
        for (int i=0; i<n; i++){
            cin >> ara[i];
        }
        while (m--){
            cin >> s;
            if (s=="P"){
                int i, j;
                cin >> i >> j;
                swap_value (i, j);
            }
            else if (s=="S"){
                int x;
                cin >> x;
                add_value (x, n);
            }
            else if (s=="M"){
                int x;
                cin >> x;
                mult_value (x, n);
            }
            else if (s=="D"){
                int x;
                cin >> x;
                div_value(x, n);
            }
            else {
                reverse (ara, ara+n);
            }
        }
        cout << "Case " << c++ << ":" << endl;
        for (int i=0; i<n; i++){

            if (i==n-1)
                cout << ara[i] << endl;

            else
                cout << ara[i] << " ";
        }
    }

    return 0;
}
