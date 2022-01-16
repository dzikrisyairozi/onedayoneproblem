#include <stdio.h>
typedef long long LL;
using namespace std;
int main(void){
    unsigned long long n;
    bool b=true;
    scanf("%llu",&n); 
    if(n&1==b){        
        n=n+1LL;
    }
    n=n/2LL;
    printf("%llu",n);
    return 0;
}