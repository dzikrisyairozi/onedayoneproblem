#include <stdio.h>
using namespace std;

int main(){
    int dp[1007], m, n;
    scanf("%d", &m);
    for(int i=1; i<=1000; i++){
        n = (i/100)*200;
        n += (i%100)/50 * 125;
        n += (i%50)/10 * 30;
        n += (i%10) * 4;
        dp[i] = n;
    }
    for(int i=999; i>0; i--){
        n = dp[i+1];
        if(dp[i] > n) dp[i] = n;
    }
    printf("%d\n", dp[m]);
    return 0;
}