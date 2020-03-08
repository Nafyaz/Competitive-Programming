#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ff first
#define ss second

int n;
bitset<1009> adj[1009], ontree;

pair<int, int> findleaf()
{
    int i, u, v, leafno = 0;
    for(i = 1; i <= n; i++)
    {
        if(leafno == 0 && adj[i].count() == 1)
        {
            leafno++;
            u = i;
        }
        else if(leafno == 1 && adj[i].count() == 1)
        {
            leafno++;
            v = i;
            return {u, v};
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(ontree[i])
            return {i, i};
    }
}

int main()
{
    int i, u, v, lca;
    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;

        ontree[u] = ontree[v] = 1;
    }

    pair<int, int> p;

    while(1)
    {
        p = findleaf();
        u = p.ff;
        v = p.ss;

        if(u == v)
        {
            cout << "! " << u << endl;
            return 0;
        }

        cout << "? " << u << " " << v << endl;
        cin >> lca;

        if(lca == u)
        {
            cout << "! " << u << endl;
            return 0;
        }
        else if(lca == v)
        {
            cout << "! " << v << endl;
            return 0;
        }

        else
        {
            for(i = 1; i <= n; i++)
            {
                if(adj[u][i-1])
                    break;
            }
            adj[u][i-1] = adj[i-1][u] = 0;

            for(i = 1; i <= n; i++)
            {
                if(adj[v][i-1])
                    break;
            }
            adj[v][i-1] = adj[i-1][v] = 0;
            ontree[u] = ontree[v] = 0;
        }
    }
}

