int n;
vector <int> adj[MAXN];
int subtree_size[MAXN];

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
