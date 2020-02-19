#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll i, j, mx = 0;
    char c;
    map<char, ll> freq, sum;
    string s;

    cin >> s;

    for(c = 'a'; c <= 'z'; c++)
    {
        freq.clear();
        sum.clear();
        for(i = 0; i < s.size(); i++)
        {
            sum[s[i]] += freq[c];
            freq[s[i]]++;

            mx = max(mx, freq[s[i]]);
            mx = max(mx, sum[s[i]]);
        }
    }

    cout << mx;
}
