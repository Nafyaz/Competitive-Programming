#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, k, ans, sign;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        ans = 0;
        sign = 1;

        while(n)
        {
            ans += sign*n;
            n /= k;
            sign *= -1;
        }

        cout << ans << "\n";
    }
}
