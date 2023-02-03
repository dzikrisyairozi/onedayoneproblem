#include<stdio.h>
using namespace std;
 
#define MAX 101
#define MOD 1000000007
#define loop(i, n) for(int i = 1; i <= n; i++)
#define loop2(i, n) for(int i = 2; i <= n; i++)
typedef long long ll;
 
 
int dp[MAX][MAX][MAX];
int n,l,r;

int calc();
 
int main() {
	while (scanf("%d %d %d", &n, &l, &r)!= EOF){
		printf("%d\n", calc());
	}
	return 0;
}

int calc(){
	dp[1][1][1] = 1;
	loop2(i,n){
		loop(j, i){
			loop(k, i){
				dp[i][j][k] = (int)(((ll)dp[i-1][j-1][k] + 
                                     (ll)dp[i-1][j][k-1] + 
                                     ((i-2)*(ll)dp[i-1][j][k]))%MOD);
				if(dp[i][j][k] < 0) dp[i][j][k] = dp[i][j][k] + MOD;
			}
		}
	}
	return dp[n][l][r];
}