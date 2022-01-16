#include <stdio.h>
#include <algorithm>
using namespace std;
const int MOD = 1e9+7;
int dp[2][5001][5001];

int main(){
    for(int i =0; i<=5000; i++){
        for(int j=0; j<=5000; j++){
            if(i==0 || j==0 || i<j) dp[0][i][j] = dp[1][i][j] = 0;
            else if(i==j){
                dp[0][i][j] = (1+dp[0][i][j-1])%MOD;
                dp[1][i][j] = (1+dp[1][i][j-1])%MOD;
            } else{
                dp[0][i][j] = (dp[0][i][j-1] + dp[1][i-j][min(i-j,j-1)])%MOD;
                dp[1][i][j] = dp[1][i][j-1];
                if(j+1 <= i-j){
                    dp[1][i][j] += dp[0][i-j][i-j]; dp[1][i][j] %= MOD;
                    dp[1][i][j] -= dp[0][i-j][j]; dp[1][i][j] %= MOD;
                    if(dp[1][i][j] < 0) dp[1][i][j] += MOD;
                }
            }
        }
    }

    int n, k;
    while(scanf("%d %d", &n, &k) != EOF){
        if(n==k){
            puts("1");
            continue;
        }
        int ans = (dp[0][n][k] - dp[0][n][k-1])%MOD;
        if(ans < 0) ans += MOD;
        ans += dp[1][n][k]; ans %= MOD;
        ans -= dp[1][n][k-1]; ans %= MOD;
        if(ans < 0) ans += MOD;
        printf("%d\n", ans);
    }

    return 0;
}