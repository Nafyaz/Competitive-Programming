#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1010;
vector<int> G[N];

int left[N];
int n, m, cas = 1;
bool vis[N];
void init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        G[i].clear();

    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
}

bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v]) continue;
        vis[v] = true;
        if (!left[v] || dfs(left[v]))
        {
            left[v] = u;
            return true;
        }
    }
    return false;
}

void solve()
{
    int ans = 0;
    memset(left, 0, sizeof(left));
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    printf("Case %d: %d\n", cas++, n - ans);

}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        init();
        solve();
    }
    return 0;
}
