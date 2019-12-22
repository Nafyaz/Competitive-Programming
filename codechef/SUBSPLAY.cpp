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
    int t, n, i, mn, x;
    string s;
    vector<int> pos[26];

    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(i = 0; i < 26; i++)
            pos[i].clear();
        mn = INT_MAX;

        for(i = 0; i < n; i++)
        {
            x = s[i] - 'a';
            if(!pos[x].empty())
                mn = min(mn, i - pos[x].back());
            pos[x].push_back(i);
        }

        cout << (mn == INT_MAX? 0 : n - mn) << endl;
    }
}
