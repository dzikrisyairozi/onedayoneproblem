#include <stdio.h>
#include <cstring>
using namespace std;
  
int getEaster(int y);
int leapYear(int m, int y); 
int getBetween(int day, int month, int year, int d, int m, int y);
 
int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
 
int main(){
    int t,d,y,m1,m2,day,ans;
    char m[10]; 
    scanf("%d", &t);
    while(t--){
        scanf("%d %s %d", &d, m, &y);
        
        if(strcmp(m, "January") == 0){
            m1=1;
        } 
        else if(strcmp(m, "February") == 0){
            m1=2;
        } 
        else if(strcmp(m, "March") == 0){
            m1=3;
        } 
        else if(strcmp(m, "April") == 0){
            m1=4;
        } 
        else if(strcmp(m, "May") == 0){
            m1=5;
        } 
        else if(strcmp(m, "June") == 0){
            m1=6;
        } 
        else if(strcmp(m, "July") == 0){
            m1=7;
        } 
        else if(strcmp(m, "August") == 0){
            m1=8;
        } 
        else if(strcmp(m, "September") == 0){
            m1=9;
        } 
        else if(strcmp(m, "October") == 0){
            m1=10;
        } 
        else if(strcmp(m, "November") == 0){
            m1=11;
        } 
        else if(strcmp(m, "December") == 0){
            m1=12;
        } 
        day = d;
        d = getEaster(y);
        if(d > 31){
            d -= 31;
            m2 = 4;
        }
        else m2 = 3;
        if(day == d && m1 == m2){
            printf("0\n");
        }
        else{
            ans = getBetween(day,m1,y,d,m2,y);
            if(ans < 0){
                y++;
                d = getEaster(y);
                if(d > 31){
                    d -= 31;
                    m2 = 4;
                }
                else m2 = 3;
                ans = getBetween(day,m1,y-1,d,m2,y);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
} 
 
int getEaster(int y){
    int d,fdigit,remain,p,A,B,C,D;
    fdigit = y/100;
    remain = y%19;
    p = ((fdigit - 15) / 2 + 202 - 11 * remain) % 30;
    A = p + 21;
    if(p == 29) A--;
    if(p == 28 && remain > 10) A--;
 
    B = (A-19) % 7;
    C = (40 - fdigit) % 4;
    if(C == 3) C++;
    if(C > 1) C++;
 
    p = y%100;
    D = (p + p/4) % 7;
    d = A + (20 - B - C - D) % 7 + 1;
    return d;
}
int leapYear(int m, int y){
    if(m <= 2) y--;
    return y/4 - y/100 + y/400;
}
int getBetween(int day, int month, int year, int d, int m, int y){
    int p1 = year * 365 + day;
    for (int i = 0; i < month - 1; i++)
        p1 += monthDays[i];
    p1 += leapYear(month, year);
 
    int p2 = y * 365 + d;
    for (int i = 0; i < m - 1; i++)
        p2 += monthDays[i];
    p2 += leapYear(m,y);
 
    return p2-p1;
} 