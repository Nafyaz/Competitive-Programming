#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int n;
vector <int> adj[maxn];
int subtree_size[maxn];

int get_subtree_size(int node, int par = -1)
{
	int ret = 1;

	for (auto next : adj[node])
    {
		if (next != par)
            ret += get_subtree_size(next, node);
	}
	return subtree_size[node] = ret;
}

int get_centroid(int node, int par = -1)
{
	for (auto next : adj[node])
    {
		if (next != par && subtree_size[next] * 2 > n)
			return get_centroid(next, node);
	}
	return node;
}

int main()
{
    int i, a, b;
	cin >> n;
	for (i = 1; i < n; i++)
    {
		a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	get_subtree_size(1);
	cout << get_centroid(1) << endl;
}
