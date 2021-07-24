#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll p = 31, mod = 1e9+9, invp = 838709685;

string s;
ll n;

ll func(ll len)
{
    ll i, x = 0, mul = 1;
    unordered_map<ll, pair<ll, ll>> freq;
    for(i = 0; i < len; i++)
    {
        x = (x + ((s[i]-'A') * mul) % mod) % mod;
        mul = (mul * p) % mod;
    }

    freq[x] = {1, 0};

    for(; i < n; i++)
    {
        x = (x + ((s[i]-'A') * mul) % mod) % mod;
        x = (((x - (s[i-len]-'A')) % mod) + mod) % mod;
        x = (x * invp) % mod;

        if(freq.find(x) != freq.end())
            freq[x] = {freq[x].ff + 1 , freq[x].ss};
        else
            freq[x] = {1, i-len+1};
    }

    ll ret = n;
    for(auto u : freq)
    {
        if(u.ss.ff == 1LL)
        {
            ret = min(ret, u.ss.ss);
        }
    }

    return ret;
}

int main()
{
    cin >> s;
    n = s.size();

//    ll flag = func(2);
//    cout << "ans: " << func(2) << "\n";

    ll low = 1, high = n, mid, st;
    pair<ll, ll> ans (300009, 300009); //ans(start, length)

    while(low <= high)
    {
        mid = (low + high)/2;

        st = func(mid);

        if(st != n)
        {
            if(ans.ss > mid)
                ans = {st, mid};
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << s.substr(ans.ff, ans.ss);
}
