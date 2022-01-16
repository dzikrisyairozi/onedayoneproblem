#include <stdio.h>
#define MOD 1000000007
int n,k,dp[1000001];

int main(){
 scanf("%d %d", &n, &k);
 dp[0] = 1;
 for(int a = 1; a<= n;a++){
  dp[a] = (2*dp[a - 1] % MOD);
  if(a >= k){
   if (a == k)
    dp[a] -= 1;
   else
    dp[a] -= dp[a - k - 1];
  }
  if(dp[a] < 0)
   dp[a] = dp[a] + MOD;
 }
 printf("%d\n", dp[n]);
 return 0;
}