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

int main()
{
    int n, i, j = 0;
    cin >> n;
    int a[n];

    map<int> mp;
    vector<int> pos[n];
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = j;
            j++;
        }
        pos[j-1].push_back(i);
    }

    int val, p;
    vector<pair<int, int> > v;
    for(i = 0; i < n; i++)
    {
        p = pos[val].size() - lower_bound(pos[val].begin(), pos[val].end(), i);

        val = mp[a[i]];

        v.push_back({p, val});
    }

    sort(v.begin(), v.end());

    for(i = 0; i < n; i++)
    {
        val = mp[a[i]];
        v.erase(lower_bound(v.begin(), v.end(), {val, INT_MIN}));

    }
}
