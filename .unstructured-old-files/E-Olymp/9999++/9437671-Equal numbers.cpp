#include <cstdio>
#include <string>
using namespace std;
 
int mod(string num, int a)
{
    int res = 0;
    for (int i = 0; i < num.length(); i++) res = (res * 10 + (int)num[i] - '0') % a;
    return res;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<1001; i++)
    {
      for(int j=1; j<10; j++)
      {
        char sb[1001] = {};
        string x;
        for(int k=0; k<i; k++) x.push_back(char(j+'0'));
        if(mod(x, n) == 0)
        {
            printf("%d %d\n", j, i);
            return 0;
        }
      }
    }
    printf("0 0\n");
}