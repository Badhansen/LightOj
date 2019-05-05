// Solved
#include<bits/stdc++.h>

using namespace std;
typedef long long lng;

lng gcd(lng a, lng b){return (b==0) ? a : gcd (b, a%b);}
lng lcm(lng a, lng b){return (a/gcd (a, b))*b;}
lng _count(lng a[], lng n, lng num)
{
    lng odd = 0, even = 0, power_set = (1 << n);
    for(int counter=1; counter<power_set; counter++){
        lng p = 1;
        for(lng j=0; j<n; j++){
            if(counter & (1 << j)){
                // if the number is not prime then we have to take LCM() of the number
                p = lcm(p, a[j]);
            }
        }
        if(__builtin_popcount(counter) & 1){
            odd += (num/p);
        }
        else{
            even += (num/p);
        }
    }
    return odd - even;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, ts = 1;
    cin >> t;
    while(t--){
        lng num, n;
        cin >> num >> n;
        lng a[n + 1];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        cout << "Case " << ts++ << ": " << num - _count(a, n, num) << endl;
    }
    return 0;
}

