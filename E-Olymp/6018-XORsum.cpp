#include <iostream>
#include <queue>
#include <functional>

using namespace std;

priority_queue<long, vector<long>, greater<long> > pq;
char com[20];
long i, k, n, t, q, xor1;

int main() {
	scanf("%ld", &t);
	while (t--)
	{
		scanf("%ld %ld\n", &q, &k);

		xor1 = 0;
		while (pq.size() > 0) pq.pop();
		for (i = 0; i < q; i++)
		{
			scanf("%s", com);

			if (com[0] == 'i')
			{
				scanf("%ld\n", &n);
				xor1 ^= n;
				pq.push(n);
			}
			else
			{
				while (pq.size() > k)
				{
					xor1 ^= pq.top();
					pq.pop();
				}
				printf("%ld\n", xor1);
			}
		}
	}
	return 0;
}