#include <stdio.h>
using namespace std;
#define MOD 1000000007
typedef long long LL;
 
LL modexp(LL b, LL e, LL m){
    LL r=1;
    while(e>0){
        if((e&1)==1){
            r = (r*b)%m;
        }
        e>>=1;
        b=(b * b)%m;
    }
    return r;
}
 
int main()
{
    int n,cases;
    LL p1, p2, p3, hasil;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &n);
        if(n>=3){
            p1=modexp(2LL,(LL)n,MOD);
            p2=(((LL)n*((LL)n-1LL))/2LL)%MOD;
            p3=((LL)n+1LL)%MOD;
            hasil=p1-p2-p3;
            while(hasil<0LL) hasil=hasil+MOD;
            printf("%lld\n", hasil);
        }
        else printf("0\n");
    }
    return 0;
}