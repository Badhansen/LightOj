#include <bits/stdc++.h>
using namespace std;


int des_cout (int num)
{
    int res=0, i=0;
    while (num!=0){
        int ck=num%10;
        res=res+(ck*pow((int)2, i));
        num/=10;
        i++;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, lps_d[4], lps_b[4], i, j, h, k, c=1, ck;
    char str_d[3], str_b[3];
    cin >> T;
    while (T--){
        i=0;
        j=0;
        ck=0;
        cin >> lps_d[i++] >> str_d[j++] >> lps_d[i++] >> str_d[j++] >> lps_d[i++] >> str_d[j++] >> lps_d[i++];
        h=0;
        k=0;
        cin >> lps_b[h++] >> str_b[k++] >> lps_b[h++] >> str_b[k++] >> lps_b[h++] >> str_b[k++] >> lps_b[h++];
        for (i=0; i<4; i++){
            int pk=des_cout(lps_b[i]);
            if (pk==lps_d[i])
                ck++;
        }
        if (ck==4)
            cout << "Case " << c++ << ": " << "Yes" << endl;
        else
            cout << "Case " << c++ << ": " << "No" << endl;

    }
    return 0;
}
