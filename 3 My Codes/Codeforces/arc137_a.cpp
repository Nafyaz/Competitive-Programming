#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll l, r, i, j, ans = 0;

    cin >> l >> r;

    for(i = l; i < r && ans < r-i; i++)
    {
        for(j = r; j > i && ans < j-i; j--)
        {
            if(__gcd(i, j) == 1)
                ans = max(ans, j-i);
        }
    }

    cout << ans;
}
