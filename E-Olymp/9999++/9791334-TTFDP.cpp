#include <stdio.h>
using namespace std;
#define LL long long
#define loop(i, n) for (int i = 0; i < n; i++)

LL i, n, k;
LL t_con = 1e9;
LL u[120], c[100], t[50];

LL calc(LL input);

int main(){
    LL minBase=30, midBase, maxBase=t_con;
    scanf("%d %d", &n, &k);
    loop(i,n){
        scanf("%d %d %d", &u[i], &c[i], &t[i]);
        LL time = u[i]*k + t[i]*(k/c[i]);
        if(time>t_con) t_con = time; 
    }
    while(minBase+1<maxBase){
        midBase = (maxBase+minBase)/2;
        if(calc(midBase)>=k) maxBase = midBase;
        else minBase = midBase;
    }
    while(calc(maxBase-1)==k){
        maxBase--;
    }
    printf("%lld", maxBase);
}

LL calc(LL input){
    LL temp_s = 0; 
    LL temp_e = 0;
    loop(i,n){
        temp_s=u[i]*c[i]+t[i];
        temp_e=temp_e+(input%temp_s)/u[i]+(input/temp_s)*c[i];
    }
    return temp_e;
}