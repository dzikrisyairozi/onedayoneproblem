#include <stdio.h>
using namespace std;
 
int main(){
	int g,q,x; 
	scanf("%d",&g);
	for(int k = 1; k<=g; ++k){
		scanf("%d",&q);
		int xud[q],dok[q],oku[q];
		dok[0] = 0;
		for(int i=0;i<q; ++i){
            scanf("%d",&x);
			xud[i] = x;
			oku[0] = xud[0]^dok[0];
			if(i >=1)oku[i] = oku[i-1]|xud[i];
			dok[i] = oku[i]^xud[i];
		}printf("Game #%d\n", k);
		for(int i=0; i<q; i++){
			printf("%d ",xud[i]);
			if(i != q-1)printf(" ");
		}printf("\n");
		for(int i=0; i<q; i++){
			printf("%d ",dok[i]);
			if(i != q-1)printf(" ");
		}printf("\n");
		for(int i=0; i<q; i++){
			printf("%d ",oku[i]);
			if(i != q-1)printf(" ");
		}printf("\n");
	}
} 