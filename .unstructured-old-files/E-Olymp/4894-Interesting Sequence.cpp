#include <stdio.h>
#include <algorithm>
using namespace std;
typedef unsigned long long LL;

int main(){
    LL n, x;
    scanf("%llu", &n);
    while(n--){
        scanf("%llu", &x);
        LL tmp = __builtin_popcountll(x-1);
        printf("%llu\n", tmp%3);
    }

    return 0;
}