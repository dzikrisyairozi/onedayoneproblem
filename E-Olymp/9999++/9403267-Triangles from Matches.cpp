#include<stdio.h>
#include<math.h>
typedef long long LL;
using namespace std;
int main(){
    LL x,y,num,n;
    scanf("%lld",&n);
    num=2*ceil((double)(n+sqrt(6.0*n))/2)-n;
    x=(3*n + num)/2;
    printf("%lld\n",x);
    return 0;
}