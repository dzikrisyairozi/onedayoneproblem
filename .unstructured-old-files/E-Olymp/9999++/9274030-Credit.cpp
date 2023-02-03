#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    double a, p, b, remain;
    int count=0;
    int day=0; 
    bool possible = true;
    scanf("%lf %lf %lf", &a, &p, &b);
    while(a>0 && possible){
        day++;
        count += (p/100) * a;
        a = (p/100)*a + a;
        if(day%7==0){
            remain=min(a, b);
            a -= remain;
            if(count > b) possible = false;
            count = 0;
        }
    }
    if(!possible){
        puts("-1");
    }
    else{
        printf("%d %.2lf\n", (day/7), remain);
    }
    return 0;
}