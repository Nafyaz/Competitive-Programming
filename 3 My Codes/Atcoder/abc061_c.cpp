#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll n, k, i, a, b;
    map<ll, ll> freq;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        freq[a] += b;
    }

    for(auto u : freq)
    {
        if(k <= u.ss)
        {
            cout << u.ff;
            break;
        }

        k -= u.ss;
    }
}
