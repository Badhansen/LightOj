// Solved
#include<bits/stdc++.h>

using namespace std;
#define MM 3000010


int lps[MM];

int build_lps(string ptr, int m, int p)
{
    lps[0] = 0;
    lps[1] = 0;

    for(int i=2; i<=m; i++){
        int j = lps[i-1];
        while(1){
            if(ptr[j] == ptr[i-1]){
                lps[i] = j + 1;
                break;
            }
            if(j == 0){
                lps[i] = 0;
                break;
            }
            j = lps[j];
        }
    }
    int cnt = 0;
    for(int i=0; i<=m; i++) if(lps[i] == p) cnt++;
    return cnt;
}
int main()
{
    int t, ts = 1;
    cin >> t;
    string text, ptr;
    while(t--){
        cin >> text >> ptr;
        text = ptr + "#" + text;
        int ans = build_lps(text, text.size(), ptr.size());
        cout << "Case " << ts++ << ": " << ans << endl;
    }

    return 0;
}
