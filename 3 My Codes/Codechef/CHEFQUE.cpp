#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mask[70000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll q, s, a, b, x, ans = 0;

    cin >> q >> s >> a >> b;

    while(q--)
    {
        x = s >> 1LL;

        if((s & 1LL) == 1 && (mask[x/64] & (1LL << (x%64))) == 0)
        {
            mask[x/64] |= (1LL << (x%64));
            ans += x;
        }
        else if((s & 1LL) == 0 && (mask[x/64] & (1LL << (x%64))) != 0)
        {
            mask[x/64] &= ~(1LL << (x%64));
            ans -= x;
        }

        s = (a*s + b) & ((1LL << 32) - 1);
    }

    cout << ans;
}
