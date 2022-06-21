#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

const int N = 30000 + 5;
int n, a[N];
vector<int> adj[N];
int parent[N], level[N], anc[N][21];//for lca
int heavy[N], subsize[N];
int chainHead[N], chainNo, basePos[N], chainIdx[N];//for hld
int base[N], cnt, tree[N*4];//for segment tree

int dfs(int node, int pr, int l)
{
    subsize[node] = 1;
    parent[node] = pr;
    level[node] = l;

    int mx = 0, x;

    for(auto u : adj[node])
    {
        if(u != parent[node])
        {
            x = dfs(u, node, l+1);
            subsize[node] += x;

            if(mx < x)
            {
                heavy[node] = u;
                mx = x;
            }
        }
    }

    return subsize[node];
}

void lca_init()
{
    int i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= 20; j++)
            anc[i][j] = 1;
    }

    for(i = 1; i <= n; i++)
        anc[i][0] = parent[i];

    for(j = 1; (1<<j) <= n; j++)
    {
        for(i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int lca(int u, int v)
{
    if(level[u] < level[v])
        swap(u, v);

    int i;
    for(i = log2(n) + 1; i >= 0; i--)
    {
        if(level[anc[u][i]] >= level[v])
            u = anc[u][i];
    }

    if(u == v)
        return u;
    for(i = log2(n) + 1; i >= 0; i--)
    {
        if(anc[u][i] != anc[v][i])
        {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return parent[u];
}

void hld_init(int u, int pr)
{
	if(chainHead[chainNo] == -1)
        chainHead[chainNo] = u;

	chainIdx[u] = chainNo;
	base[cnt++] = a[u];
	basePos[u] = cnt-1;

	if(heavy[u] > -1)
        hld_init(heavy[u], u);
	for(auto v : adj[u])
	{
		if(v != pr and v != heavy[u])
		{
			chainNo++;
			hld_init(v, u);
		}
	}
}

void build_tree(int node, int s, int e)
{
    if(s == e)
    {
        tree[node] = base[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node, right = 2*node+1;

    build_tree(left, s, mid);
    build_tree(right, mid+1, e);

    tree[node]= tree[left] + tree[right];
}

void update_tree(int node, int s, int e, int pos, int val)
{
    if(s > pos || e < pos)
        return;
    if(s == e)
    {
        base[s] = val;
        tree[node] = val;
        return;
    }

    int mid = (s+e)/2, left = 2*node, right = 2*node+1;

    update_tree(left, s, mid, pos, val);
    update_tree(right, mid+1, e, pos, val);

    tree[node] = tree[left] + tree[right];
}

int query_tree(int node, int s, int e, int lo, int hi)
{
    if(hi < s || lo > e)
        return 0;
    if(lo <= s && hi >= e)
        return tree[node];

    int mid = (s+e)/2, left = 2*node, right = 2*node+1;
    int p1 = query_tree(left, s, mid, lo, hi);
    int p2 = query_tree(right, mid+1, e, lo, hi);

    return p1+p2;
}

int query_up(int u, int p)
{
	int uchain, pchain = chainIdx[p], ret = 0;

	while(1)
    {
		uchain = chainIdx[u];

		if(uchain == pchain)
		{
			ret += query_tree(1, 1, n, basePos[p], basePos[u]);
			break;
		}
		ret += query_tree(1, 1, n, basePos[chainHead[uchain]], basePos[u]);
		u = chainHead[uchain];
		u = parent[u];
	}
	return ret;
}

void update_hld(int p, int val)
{
    update_tree(1, 1, n, basePos[p], val);
}

int query_hld(int u, int v)
{
    int l = lca(u, v);
    return query_up(u, l) + query_up(v, l) - query_up(l, l);
}

void init()
{
    int i;
    for(i = 0; i <= n; i++)
    {
        heavy[i] = -1;
        chainHead[i] = -1;
    }
    dfs(1, 1, 0);
    lca_init();
    cnt = 1, chainNo = 1;
    hld_init(1, 1);
    build_tree(1, 1, n);
}

int main()
{
    int t, i, q, caseno = 0, u, v;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            adj[i].clear();
        }

        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u+1].push_back(v+1);
            adj[v+1].push_back(u+1);
        }

        init();

        printf("Case %d:\n", ++caseno);
        scanf("%d", &q);

        while(q--)
        {
            int type, x, y;
            scanf("%d %d %d", &type, &x, &y);
            if(type)
                update_hld(x+1, y);
            else
                printf("%d\n", query_hld(x+1, y+1));
        }
    }
}