#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int parent[100009];

int find(int u)
{
    if(parent[u] == u)
        return u;
    parent[u] = find(parent[u]);
    return parent[u];
}

void add(int u, int v)
{
    int x = find(u);
    int y = find(v);

    parent[x] = parent[y];
}

int main()
{
    int q, i = 1, x, y;
    for(i = 1; i < 100009; i++)
        parent[i] = i;
    string a, b;
    map<string, int> mp;
    cin >> q;

    i = 1;
    while(q--)
    {
        cin >> a >> b;
        if(mp.find(a) == mp.end())
        {
            mp[a] = i;
            i++;
        }
        if(mp.find(b) == mp.end())
        {
            mp[b] = i;
            i++;
        }

        x = mp[a];
        y = mp[b];

        if(find(x) == find(y))
            cout << "Found in friend list" << endl;
        else
            cout << "Found by random" << endl;


        add(mp[a], mp[b]);
    }
}
