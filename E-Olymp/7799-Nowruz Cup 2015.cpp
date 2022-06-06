#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int i, n, a[200001];
multiset<int> st;
multiset<int>::iterator iter;


int GetMax()
{

	int amans_pair = a[1] + a[n];

	for (i = 2; i <= n - 1; i++) st.insert(a[i]);
	int pos = 1;
	while (!st.empty())
	{
		iter = st.end(); --iter;
		int val = *iter;
		st.erase(iter);
		iter = st.upper_bound(amans_pair - val);
		if (iter == st.begin())
		{
			pos++;
			iter = st.end(); --iter;
			st.erase(iter);
			continue;
		}
		--iter;
		st.erase(iter);
	}
	return pos;
}

int GetMin()
{

	int amans_pair = a[1] + a[2];

	for (i = 3; i <= n; i++) st.insert(a[i]);
	int pos = 1;
	while (!st.empty())
	{
		int val = *st.begin();
		st.erase(st.begin());
		iter = st.upper_bound(amans_pair - val);
		if (iter == st.end()) st.erase(st.begin());
		else
		{
			st.erase(iter);
			pos++;
		}
	}
	return pos;
}

int main() {
	scanf("%d", &n); n = 2 * n;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 2, a + n + 1);
	printf("%d %d\n", GetMax(), GetMin());
	return 0;
}