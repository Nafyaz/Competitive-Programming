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

int g, s, b, n, p[400009];

bool check(int total)
{
    if(total != n && p[total - 1] == p[total])
        return 0;

    g = s = b = 0;
    map<int, int> mp;
    for(int i = 0; i < total; i++)
        mp[p[i]]++;

    vector<pair<int, int> > v;
    for(auto u : mp)
    {
//        cout << u.ff << " " << u.ss << endl;
        v.push_back({u.ff, u.ss});
    }

    if(v.size() < 3)
        return 0;
    g = v[v.size() - 1].ss;
//    cout << "g" << g << endl;
    total -= g;
    int sum = 0;
    for(int i = v.size() - 2; i >= 0; i--)
    {
        sum += v[i].ss;
        if(sum > g && total - sum > g && total - sum && sum)
        {
            s = sum;
            b = total - sum;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t, i, low, high, mid, flag;
    int ansg, anss, ansb;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> p[i];

        ansg = anss = ansb = 0;

        for(mid = n/2; mid > 3; mid--)
        {
            if(check(mid))
            {
                if(ansg + anss + ansb < g+s+b)
                {
                    ansg = g;
                    anss = s;
                    ansb = b;
                }
                break;
            }
        }
        cout << ansg << " " << anss << " " << ansb << endl;

    }
}
