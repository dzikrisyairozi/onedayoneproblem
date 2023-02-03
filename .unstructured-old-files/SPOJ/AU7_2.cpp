#include <iostream>
using namespace std;
 
long long calcNum();
long long calcTime(long long sum);
 
int x, y;
int z[100007];
 
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int lowerBase = 2147483647;
        x = calcNum();
        y = calcNum();
        for(int i=0; i<x; i++){
            z[i] = calcNum();
            if(lowerBase < z[i]){
                lowerBase = z[i];
            }
        }
        long long minBase = 0;
        long long maxBase = (long long) z[0]*y;
        
        while(maxBase > minBase + 1){
            long long midBase;
            midBase = (minBase + maxBase) >> 1;
            if(calcTime(midBase)==0){
                minBase = midBase;
            }
            else{
                maxBase = midBase;
            }
        }
        cout << maxBase << endl;
    }
 
    return 0;
}
 
long long calcTime(long long sum){
    long long count;
    count = 0;
    for(int i=0;i<x;i++){
        long long temp;
        temp = sum/z[i];
        if(temp + count >= y || temp >=y){
            return 1;
        }
        count = count + temp;
    }
    return count >= y;
}
 
long long calcNum(){
    long long sum;
    sum = 0;
    char w;
    while(1){
        cin.get(w);
        if(w =='\n' || w == ' '){
            continue;
        }
        else{
            break;
        }
    }
    sum = w - '0';
    while(1){
        cin.get(w);
        if(w <= '9' && w >= '0'){
            sum = sum*10 + w -'0';
        }
        else{
            break;
        }
    }
    return sum;
}