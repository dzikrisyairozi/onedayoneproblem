#include <cstdio>
using namespace std;
int main(){
 int a,b,c,d;
 scanf("%d", &a);
 while (a--){
  scanf("%d %d", &b, &c);
  b=b*30; c=(c/5)*30; d = b-c;
  if (d>180)d=360-d;
  else if((d<-180) && (d>=-360))d=d+360;
  else if((d>=-180) && (d<0))d=d*-1;
  printf("%d\n", d);
 }
} 