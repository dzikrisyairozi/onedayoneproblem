#include <iostream>
#include <math.h>
#include <algorithm>
typedef long long LL;
using namespace std;

int t, E, N;
 
int main(){
    cin >> t;
    while(t--){
        scanf("%d %d",&E, &N);  
        int ans = 0;
        for(int i=0; i+i<=E && i<=N; i++){
            ans= max(ans,i + min(E - i - i, (N-i) >> 1 ));
        }
         cout << ans << endl;
    }
    return 0;
}