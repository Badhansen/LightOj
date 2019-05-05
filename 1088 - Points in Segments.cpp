// solved
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, ts = 1;
    //cin >> t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        //cin >> n >> q;
        scanf("%d%d", &n, &q);
        vector<int> v;
        for(int i=0; i<n; i++){
            int a;
            //cin >> a;
            scanf("%d", &a);
            v.push_back(a);
        }
        //cout << "Case " << ts++ << ":" << endl;
        printf("Case %d:\n", ts++);
        while(q--){
            int a, b;
            //cin >> a >> b;
            scanf("%d%d", &a, &b);
            int l = lower_bound(v.begin(), v.end(), a) - v.begin();
            int r = lower_bound(v.begin(), v.end(), b + 1) - v.begin();
            //cout << r - l << endl;
            printf("%d\n", r - l);

        }
    }
    return 0;
}

