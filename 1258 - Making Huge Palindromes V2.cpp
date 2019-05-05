// Solved
#include<bits/stdc++.h>

using namespace std;

const int MaxN = 2e6 + 10;
int lps[MaxN];

void KMPprocess(string ptr, int m)
{
    int i = 0, j = -1;
    lps[i] = j;
    while(i < m){
        while(j >= 0 && ptr[i] != ptr[j])
            j = lps[j];
        i++, j++;
        lps[i] = j;
    }
}
int KMPsearch(string txt, string ptr)
{
    int i = 0, j = 0, n = txt.size(), m = ptr.size();
    KMPprocess(ptr, m);
    while(i<n){
        while(j >= 0 && txt[i] != ptr[j])
            j = lps[j];
        i++, j++;
        if(j == m){
            return j;
        }
    }
    return j;
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
        int n = KMPsearch(str, ptr);
        int ans = 2*sz - n;
        cout << "Case " << ts++ << ": " << ans << endl;
    }


    return 0;
}
