#include <iostream>

using namespace std;

#define MAX 1000001

int i, n, m, l, q, r, x, sum, cnt[MAX], coins[MAX];

int main() {

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &l, &r);
		cnt[l]++; cnt[r + 1]--;
	}

	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += cnt[i];
		coins[sum]++;
	}

	for (i = MAX - 2; i >= 0; i--) coins[i] += coins[i + 1];


	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &x);
		printf("%d\n", coins[x]);
	}
	return 0;
}