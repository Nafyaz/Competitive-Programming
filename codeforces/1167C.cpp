#include<bits/stdc++.h>
using namespace std;

#define N 500010
int parent[N], friends[N];

int find(int x)
{
    if(parent[x] == x)
        return parent[x];
    else
        parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y)
{
    int u = find(x);
    int v = find(y);

    parent[v] = u;
    friends[u] = friends[u] + friends[v];
}

int main()
{
    int n, m, k, x, y, i, j;
    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        parent[i] = i;
        friends[i] = 1;
    }

    for(i = 0; i < m; i++)
    {
        scanf("%d", &k);
        for(j = 0; j < k; j++)
        {
            scanf("%d", &y);
            if(j == 0)
                x = y;
            else if(find(x) != find(y))
                merge(x, y);
        }
    }

    for(i = 1; i <= n; i++)
        printf("%d ", friends[find(i)]);
}
