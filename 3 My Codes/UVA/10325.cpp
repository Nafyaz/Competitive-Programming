#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, m, i, j, a[15], mask, ans, lcm;

    while(cin >> n >> m)
    {
        for(i = 0; i < m; i++)
            cin >> a[i];

        ans = 0;
        for(mask = 0; mask < (1 << m); mask++)
        {
            lcm = 1;
            for(i = 0; i < m; i++)
            {
                if(mask & (1<<i))
                    lcm = lcm*a[i]/ __gcd(lcm, a[i]);
            }

            if(__builtin_popcount(mask) % 2 == 1)
                ans -= n/lcm;
            else
                ans += n/lcm;

//            cout << mask << " " << ans << "\n";
        }

        cout << ans << "\n";
    }
}
