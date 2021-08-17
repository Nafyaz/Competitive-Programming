#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll base = 257, mod = 1e9+7;

ll n, p[90];
ll Hash[90];

bool isPeriod(ll i)
{
    ll HashA, HashB;

    HashA = Hash[n-i];
    HashB = ((Hash[n] - (Hash[i] * p[n-i])%mod) % mod + mod) % mod;

    return HashA == HashB;
}

int main()
{
    ll t, i, ans;

    p[0] = 1;
    for(i = 1; i < 90; i++)
        p[i] = (p[i-1]*base) % mod;

    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;
        n = s.size();

        for(i = 0; i < n; i++)
        {
            Hash[i+1] = (Hash[i] * base) % mod;

            Hash[i+1] = (Hash[i+1] + s[i] + 1) % mod;
        }

        ans = INT_MAX;

        for(i = 1; i*i <= n; i++)
        {
            if(n % i == 0)
            {
                if(isPeriod(i))
                    ans = min(ans, i);
                if(isPeriod(n/i))
                    ans = min(ans, n/i);
            }
        }

        cout << ans << "\n";

        if(t)
            cout << "\n";
    }
}
