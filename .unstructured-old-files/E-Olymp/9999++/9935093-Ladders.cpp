#include <cstdio>
using namespace std;
int n, dp[202];

int main(){
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1; i<=n; i++){
        for(int j=n; j>=0; j--){
            if(dp[j])dp[j+i] += dp[j];
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}