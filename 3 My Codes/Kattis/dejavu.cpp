#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

vector<ll> rows[100009], cols[100009];

int main()
{
    ll i, n, x, y;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        rows[y].push_back(x);
        cols[x].push_back(y);
    }

    ll ans = 0;
    for(i = 1; i < 100009; i++)
    {
        for(auto p : cols[i])
            ans += ((ll)cols[i].size() - 1) * ((ll)rows[p].size() - 1);
    }

    cout << ans;
}
