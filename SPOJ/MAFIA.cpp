#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int n,i, ans, tmp;
    pair<int, int> interval[22];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &interval[i].second, &interval[i].first);
    sort(interval, interval+n);
    ans = 1;
    tmp = interval[0].first;
    for(int i = 1;i<n;i++){ 
        if(interval[i].second > tmp){
            ans++;
            tmp = interval[i].first;
        }
    }
    printf("%d\n",ans);
} 