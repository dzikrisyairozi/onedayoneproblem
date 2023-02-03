#include <stdio.h>
typedef long long LL;
using namespace std;

LL n, m, ans; 

int main(){
    m = 0;
    scanf("%d", &n);
    while(m*m < n ){
        m++;
    } 
    m--; 
    ans += m*(m+1)*2;
    ans += (n-m*m)*2;
    ans++;
    if(n-m*m>m){
        ans++;
    }
    printf("%d\n", ans);
}