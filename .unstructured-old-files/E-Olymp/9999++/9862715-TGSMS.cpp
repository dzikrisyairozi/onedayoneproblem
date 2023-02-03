#include<stdio.h>
#include<algorithm>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define loop1(i, n) for(int i = 1; i < n; i++)

int calc(int *arr, int n);

int main(){
    int n,arr[1007];
    scanf("%d",&n);  
    loop(i, n){ 
        scanf("%d",&arr[i]); 
    } 
    int ans = calc(arr, n);
    printf("%d\n", ans);
    return 0; 
}

int calc( int *arr, int n ){
    int temp,lds[n];
    temp = 0;
    lds[0] = 1;  
    loop1(i,n){
        lds[i] = 1;
        loop(j,i){ 
            if (arr[j] != 0 && arr[i] % arr[j] == 0){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    loop(i,n){
        if(lds[i]>temp){
            temp = lds[i];
        }
    }
    return temp;
}