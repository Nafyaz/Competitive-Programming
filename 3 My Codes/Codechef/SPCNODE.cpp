#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1003];
int n;
int subtree_size[1003];
bool dead[1003];

int get_subtree_size(int node, int par = -1)
{
    int ret = 1;

    for(auto next : adj[node])
    {
        if(next != par && !dead[next])
            ret += get_subtree_size(next, node);
    }

    return subtree_size[node] = ret;
}

int get_centroid(int node, int par = -1)
{
    for(auto next : adj[node])
    {
        if(next != par && !dead[next] && subtree_size[next] * 2 > n)
            return get_centroid(next, node);
    }

    return node;
}

int main()
{
    int T, i, u, v, y, x;

    cin >> T;

    while(T--)
    {
        cin >> n;

        memset(dead, 0, sizeof dead);
        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        y = 1;
        while(1)
        {
            get_subtree_size(y);
            y = get_centroid(y);

            cout << "? " << y << "\n";
            cin >> x;

            if(x == -1)
            {
                cout << "! " << y << "\n";
                break;
            }

            dead[y] = 1;
            n = subtree_size[y] - 1;
            y = x;
        }
    }
}
