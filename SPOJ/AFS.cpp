#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
template<typename T>
T getNum(){
    T res=0;
    char c;
    while(1){
        c=getchar_unlocked();
        if(c==' '||c=='\n')continue;
        else break;
    }
    res=c-'0';
    while(1){
        c=getchar_unlocked();
        if(c>='0'&&c<='9')res=10*res+c-'0';
        else break;
    }
    return res;
}
 
int main(){
    int T;
    LL n, a, a1, a2, ans, sum;
    T=getNum<int>();
    while(T--){
        n=getNum<LL>();
        ans=0;
        for(a=2; a*a <=n; ++a){
            a1=(a+1);
            a2=n/a;
            if(a1<=a2){
                sum = (a2*(a2+1))/2-(a1*(a1-1))/2;
                ans+=sum;
                ans+=a*(a2-a1+1);
            }
            ans+=a;
        }
        ans+=n-1;
        printf("%lld\n",ans);
    }
    return 0;
} 