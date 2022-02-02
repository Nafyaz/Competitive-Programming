#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int p[N];
int sz[N];
int ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++)
		sz[i] = 1;
	for (int i = n - 1; i > 0; i--)
		sz[p[i]] += sz[i];
	for (int i = n - 1; i > 0; i--)
		ans[i] = sz[p[i]] + 1 - sz[i];
	ans[0] = 2;
	for (int i = 1; i < n; i++)
		ans[i] += ans[p[i]];
	for (int i = 0; i < n; i++)
		printf("%.1lf ", (double)ans[i] / 2);
	printf("\n");

	return 0;
}
