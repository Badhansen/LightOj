#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, x1, y1, x2, y2, m, c=1;
    cin >> T;
    while (T--){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        cout << "Case " << c++ << ":" << endl;
        while (m--){
            int a, b;
            cin >> a >> b;
            if ((a>=x1 && a<=x2) && (b>=y1 && b<=y2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
