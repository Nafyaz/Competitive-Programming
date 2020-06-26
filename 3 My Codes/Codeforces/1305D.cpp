#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define ff first
#define ss second

int n;
bitset<1009> ontree;
set<int> adj[1009];

pair<int, int> findleaf()
{
    int i, u, v, leafno = 0;
    for(i = 1; i <= n; i++)
    {
        if(leafno == 0 && adj[i].size() == 1)
        {
            leafno++;
            u = i;
        }

        else if(leafno == 1 && adj[i].size() == 1)
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
    int i, j, u, v, lca;
    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        ontree[u] = ontree[v] = 1;
    }

   pair<int, int> p;

    while(1)
    {
//        cout << "adj: " << endl;
//        for(i = 1; i <= n; i++)
//        {
//            cout << i << ": ";
//            for(auto u : adj[i])
//                cout << u << " ";
//            cout << endl;
//        }

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
//            cout << "values: " << u << " " << *adj[u].begin() << ", " << v << " " << *adj[v].begin() << endl;
            adj[*adj[u].begin()].erase(u);
            adj[*adj[v].begin()].erase(v);
            adj[u].clear();
            adj[v].clear();
            ontree[u] = ontree[v] = 0;
        }
    }

}
