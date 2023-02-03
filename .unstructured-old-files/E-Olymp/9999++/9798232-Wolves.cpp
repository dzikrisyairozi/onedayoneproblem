#include <stdio.h>
#include <math.h>
using namespace std;
#define LL long long
#define loop(i, n) for (int i = 0; i < n; i++)

LL i,n,k,p[100010];

LL calc(double input);

int main(){
    while(scanf("%d %d", &k, &n)!=EOF && n!=0 && k!=0){
        double totalStrength = 0;
        loop(i,n){
            scanf("%lld", &p[i]);
            totalStrength +=p[i];
        }
        if(n>k) printf("Impossible\n");        
        else{
            double maxBase = totalStrength;
            double minBase = 1/(double)k;
            while(maxBase - minBase > 0.000001){
                double midBase = (maxBase+minBase)*0.5;
                if(calc(midBase)<=k) maxBase = midBase;
                else minBase = midBase;
            }
            while(calc(maxBase-1)==k){
                maxBase--;
            }
            printf("%.6lf\n", maxBase);
        }
    }
}

LL calc(double input){
    int temp=0;
    loop(i,n){
       temp=temp+ceil((double)p[i]/input); 
    }
    return temp;
}