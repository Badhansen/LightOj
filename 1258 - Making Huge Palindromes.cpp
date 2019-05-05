// Solved
#include<bits/stdc++.h>
using namespace std;
const int MaxN = 3e6 + 10;

int lps[MaxN];

void build_lps(string ptr, int m)
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
}
int KMP(string text, string ptr)
{
    int n = text.size(), m = ptr.size();
    build_lps(ptr, m);
    int i = 0, j = 0;
    while(1){
        if(j == n) break;
        if(text[j] == ptr[i]){
            i++, j++;
            if(i == m) return i;
        }
        else{
            if(i == 0){
                j++;
            }
            else{
                i = lps[i];
            }
        }

    }
    return i;
}
int main()
{
    int t, ts = 1;
    cin >> t;
    while(t--){
        string str, ptr;

        cin >> str;

        ptr = str;
        reverse(ptr.begin(), ptr.end());

        int sz = str.size();
        int n = KMP(str, ptr);
        int ans = 2*sz - n;
        cout << "Case " << ts++ << ": " << ans << endl;
    }

    return 0;
}

