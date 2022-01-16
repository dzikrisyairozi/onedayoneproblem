#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
long long data[10010],mid,high,low,sum,MX;

long long calc(long long u){
    long long temp = 0;
    for(int i=0; i<n; i++) temp += (data[i]/u);
    return temp;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    sum = 0; MX = 0;
    for(int i=0; i<n; i++){
        cin >> data[i];
        if(MX<data[i]) MX = data[i];
        sum += data[i];
    }
    if(sum < k) printf("0");
    else if(sum == k) printf("1");
    else{
        high = min(MX+1, sum/k+1);
        low = 1;
        while(true){
            if(high-1 == low) break;
            mid = (high+low)/2;
            if(calc(mid)<k){
                high = mid;
            } else{
                low = mid;
            }
        }
        printf("%lld",low);
    }
    printf("\n");
    return 0;
}