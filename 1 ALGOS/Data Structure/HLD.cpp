/**
 * Heavy Light Decomposition
 * Build Complexity O(n)
 * Query Complexity O(lg^2 n)
 * Call init() with number of nodes
 * It's probably for the best to not do "using namespace hld"
**/
namespace hld {
	/**
	 * N is the maximum number of nodes
	 * g is the adjacency graph
	 * par, lev, size corresponds to parent, depth, subtree-size
	 * head[u] is the starting node of the chain u is in
	 * in[u] to out[u] keeps the subtree indices
	**/
	const int N = 100000+7;
	vector<int> g[N];
	int par[N], lev[N], head[N], size[N], in[N], out[N];
	int cur_pos, n;

	/**
	 * returns the size of subtree rooted at u
	 * maintains the child with the largest subtree at the front of g[u]
	 * WARNING: Don't change anything here specially with size[] if Jon Snow
	**/
	int dfs(int u, int p) {
		size[u] = 1;
		par[u] = p;
		lev[u] = lev[p] + 1;
		for(auto &v : g[u]) {
			if(v == p) continue;
			size[u] += dfs(v, u);
			if(size[v] > size[g[u].front()]) {
				swap(v, g[u].front());
			}
		}
		return size[u];
	}

	/**
	 * decomposed the tree in an array
	 * note that there is no physical array here
	**/
	void decompose(int u, int p) {
		in[u] = ++cur_pos;
		for(auto &v : g[u]) {
			if(v == p) continue;
			head[v] = (v == g[u].front() ? head[u] : v);
			decompose(v, u);
		}
		out[u] = cur_pos;
	}

	/**
	 * initializes the structure with _n nodes
	**/
	void init(int _n, int root = 1) {
		n = _n;
		cur_pos = 0;
		dfs(root, 0);
		head[root] = root;
		decompose(root, 0);
	}

	/**
	 * checks whether p is an ancestor of u
	**/
	bool isances(int p, int u) {
		return in[p] <= in[u] and out[u] <= out[p];
	}

	/**
	 * Returns the maximum node value in the path u - v
	**/
	ll query(int u, int v) {
		ll ret = -INF;
		while(!isances(head[u], v)) {
			ret = max(ret, seg.query(1, 1, n, in[head[u]], in[u]));
			u = par[head[u]];
		}
		swap(u, v);
		while(!isances(head[u], v)) {
			ret = max(ret, seg.query(1, 1, n, in[head[u]], in[u]));
			u = par[head[u]];
		}
		if(in[v] < in[u]) swap(u, v);
		ret = max(ret, seg.query(1, 1, n, in[u], in[v]));
		return ret;
	}

	/**
	 * Adds val to subtree of u
	**/
	void update(int u, ll val) {
		seg.update(1, 1, n, in[u], out[u], val);
	}
};
