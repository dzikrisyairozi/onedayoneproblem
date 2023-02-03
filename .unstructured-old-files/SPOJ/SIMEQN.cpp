#include <cstdio>
using namespace std;
 
long long count(long long val);
 
int main(){
    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        int n,a,b,c;
        scanf("%d %d %d %d",&n,&a,&b,&c);
        long long ans = count(n) - count(n-a-1) - count(n-b-1) - count(n-c-1) +
                        count(n-a-b-2) + count(n-b-c-2) + count(n-a-c-2) - count(n-a-b-c-3);
        printf("%lld\n",ans);
    }
    return 0;
}
 
long long count( long long val ){
	if(val<0){
	    return 0;
	}
	return (val+3)*(val+2)*(val+1)/6;
} 