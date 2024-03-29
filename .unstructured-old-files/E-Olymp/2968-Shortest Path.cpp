#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAX 5001
#define INF 0x3F3F3F3F3F3F3F3FL

int i, j, n, m, s, u, v, used[MAX];
long w, d[MAX];

struct node
{
	int to;
	long dist;
	node(int to, long dist) : to(to), dist(dist) {};
};
vector<vector<node>> g;

void Bellman_Ford()
{
	int i, j, k;
	memset(d, 0x3F, sizeof d);

	d[s] = 0;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 0; k < g[j].size(); k++)
			{
				int to = g[j][k].to;
				long dist = g[j][k].dist;
				if (d[j] < INF && d[to] > d[j] + dist) d[to] = d[j] + dist;
			}
}

void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].to;
		if (!used[to]) dfs(to);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	g.resize(n + 1);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %lld", &u, &v, &w);
		g[u].push_back(node(v, w));
	}
	Bellman_Ford();
	memset(used, 0, sizeof used);
	for (i = 1; i <= n; i++) {
		for (j = 0; j < g[i].size(); j++)
		{
			int to = g[i][j].to;
			long dist = g[i][j].dist;
			if (d[i] < INF && d[to] > d[i] + dist && !used[to]) dfs(to);
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (d[i] == INF) printf("*\n");
		else if (used[i]) printf("-\n");
		else printf("%ld\n", d[i]);
	}
	return 0;
}
