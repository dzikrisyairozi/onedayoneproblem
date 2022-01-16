#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int h, w; 
    int cR, cC, tR, tC;
    char ch[2];
    scanf("%d %d",&h, &w); 
    scanf("%d %d",&cR, &cC);
    scanf("%d %d",&tR, &tC);
    scanf("%s",ch);
    char avantGarde = ch[0];
    int dR = abs(cR-tR);  
    int dC = abs(cC-tC);
    int count;
	if(h == 1 || w == 1){
		if(h == 1){
			swap(h, w);
			swap(cR,cC);
			swap(tR,tC);
		}
		if(tR < cR){
			cR = h - cR + 1;
			tR = h - tR + 1;
		}
		count = 0;
		if(avantGarde == 'C'){
			count++;
			cR++;
		}
		if(cR != tR){
			if((tR-cR)%2 == 1) count++;
			count += 2*(h-cR-1);
		}
		printf("%d\n", count);
		return 0;
	}
    if(((dR+dC)%2 == 1 && avantGarde == 'T') || ((dR+dC)%2 == 0 && avantGarde == 'C')){
		puts("0");
		return 0;
	}
    if(dR < dC){
		swap(h, w);
		swap(cR,cC);
		swap(tR,tC);
		swap(dR,dC);
	}
	if(tR < cR){
		cR = h - cR + 1;
		tR = h - tR + 1;
	}
	count = 0;
	if(avantGarde == 'C'){
		count++;
		cR++;
		dR--;
	}
	if(dR != 0){
		count += 2*(h-cR-1);
		if(dR == dC){
			if(cC < tC) count += (w -1 -cC)*2;
			else count += (cC - 2)*2;
		}
		else{
			count += max(cC-2, w-1-cC)*2;
		}
		count += 2;
	}
    printf("%d", count);
    return 0;
}