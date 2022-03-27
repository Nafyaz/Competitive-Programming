#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, layer, parity, odd, even;
    map<pair<ll, ll>, bool> mp;

    cin >> n;

    for(layer = 0; 2*layer < n; layer++)
    {
        parity = (layer%2 == 0);
        for(i = -layer; i <= layer; i++)
        {
            mp[{i, layer}] = parity;
            parity ^= 1;
        }

        parity = (layer%2 == 0);
        for(i = -layer; i <= layer; i++)
        {
            mp[{-layer, i}] = parity;
            parity ^= 1;
        }

        parity = (layer%2 == 0);
        for(i = -layer; i <= layer; i++)
        {
            mp[{layer, i}] = parity;
            parity ^= 1;
        }

        parity = (layer%2 == 0);
        for(i = -layer; i <= layer; i++)
        {
            mp[{i, -layer}] = parity;
            parity ^= 1;
        }
    }

    i = 0;
    odd = 1;
    even = 2;
    for(auto u : mp)
    {
        if(u.ss)
        {
            cout << odd << " ";
            odd += 2;
        }
        else
        {
            cout << even << " ";
            even += 2;
        }

        i++;
        if(i == n)
        {
            cout << "\n";
            i = 0;
        }
    }
}
