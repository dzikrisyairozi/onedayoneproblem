#include <stdio.h>
typedef long long LL;
using namespace std;

int main(){
    LL n, k;
    LL plus, minus;
    scanf("%lld %lld", &n, &k);
    minus = 1+k+(2 *(((k-1)*k/2) -1));
    plus = n* ((k*(k+1))/2);
    printf("%lld\n", plus-minus);

    return 0;
}