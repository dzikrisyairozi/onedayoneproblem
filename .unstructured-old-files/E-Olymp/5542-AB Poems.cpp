#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

#define MAX 1001
char Pa[MAX], Pb[MAX], w[MAX];
int a, b, c, d, t, x, y, x2, y2, disc;
double res;


void CountAB(char *s, int &a, int &b)
{
	for (int i = a = b = 0; i < strlen(s); i++) (s[i] == 'a' ? a : b)++;
}

int main() {

	scanf("%d\n", &t);
	while (t--)
	{
		cin >> Pa; CountAB(Pa, a, b);
		cin >> Pb; CountAB(Pb, c, d);
		cin >> w;  CountAB(w, x, y);

	
		x2 = a * x + c * y;
		y2 = b * x + d * y;


		if (y * x2 == x * y2) res = x ? 1.0 * x2 / x : 1.0 * y2 / y;
		else 
		{
			if (!a && !d) {
				if (b == c) res = b;
				else
				{
					printf("-\n");
					continue;
				}
			}
			else
			{

				disc = (a - d) * (a - d) + 4 * b * c;

				res = (a + d + sqrt(disc)) / 2.0;
			}
		}
		printf("%.12lf\n", res);
	}
	return 0;
}