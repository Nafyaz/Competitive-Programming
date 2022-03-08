#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll fib[200005];
ll a[200005];
set<ll> s;

bool isDuplicate(ll x)
{
    while(x > 1 && (x%2 == 1 || x%4 == 0))
    {
        if(s.find(x) != s.end())
            return 1;

        if(x%2 == 1)
            x /= 2;
        else if(x%4 == 0)
            x /= 4;
    }

    return s.find(x) != s.end();
}

int main()
{
    ll n, p, i, ans, space;

    fib[0] = fib[1] = 1;
    for(i = 2; i < 200005; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % mod;

    cin >> n >> p;
    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    ans = 0;
    for(i = 0; i < n; i++)
    {
        if(!isDuplicate(a[i]))
        {
            s.insert(a[i]);

            space = p - (ll)(log2(a[i])+1);

            if(space >= 0)
                ans = (ans + fib[space+2]-1) % mod;
        }
    }

    cout << ans;
}
