#include<bits/stdc++.h>
using namespace std;

int n, x, y, found;
vector <int> adj[300010];
int color[300010], vis[300010], one = 0, two = 0, three = 0;

void color2(int p)
{
    if(p == y)
    {
        found = 1;
        return;
    }

    vis[p] = 1;
    for(auto u : adj[p])
    {
        if(!vis[u])
            color2(u);
        if(found)
        {
            color[p] = 2;
            two++;
        }
    }
}

int main()
{
    int i, u, v;
    scanf("%d %d %d", &n, &x, &y);

    for(i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color2(x);

    for(i = 1; i <= n; i++)
        printf("%d %d\n", i, color[i]);
}
//18 7 14
//1 2
//2 3
//3 4
//2 5
//5 6
//5 7
//7 10
//7 8
//7 9
//9 10
//10 11
//11 12
//11 13
//10 14
//14 15
//14 16
//16 17
//17 18
