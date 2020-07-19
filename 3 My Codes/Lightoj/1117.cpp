#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x[20], n, m;

ll func(ll mask)
{
    ll i, lcm = 1;
    for(i = 0; i < m; i++)
    {
        if(mask & (1<<i))
            lcm = lcm * x[i] / __gcd(lcm, x[i]);
    }

    ll ret = n / lcm;
    ret = (__builtin_popcount(mask) & 1)? -ret : ret;

//    bitset<4> bs = mask;
//    cout << bs << " " << (__builtin_popcount(mask) & 1) << " " << ret << endl;

    return ret;
}

int main()
{
    ll t, caseno = 0, i, j, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(i = 0; i < m; i++)
            cin >> x[i];

        ans = 0;
        for(i = 0; i < (1 << m); i++)
            ans += func(i);
        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
