#include<stdio.h>
#include<math.h>
/*

    @author: Badhan Sen
    CSE, JUST.
    mail: galaxybd9@gmail.com
    CPU: .008s
    Solved
*/





int main ()
{
    int t, cnt=1;

    scanf("%d", &t);
    while(t--){
        long long int w;

        scanf("%lld", &w);
        if(w&1LL){

           printf("Case %d: Impossible\n", cnt++);
        }
        else{
            for(long long int i=1; i<=63; i++){
                long long int j=w>>i;
                if(j&1LL){

                    printf("Case %d: %lld %lld\n", cnt++, j, (2LL << i-1));
                    break;
                }
            }
        }

    }

    return 0;
}

