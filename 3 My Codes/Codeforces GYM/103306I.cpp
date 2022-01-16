#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll call(ll n)
{
    if(n == 0)
        return 0;

    ll ret = 1;

    while(n)
    {
        ret *= (n%10);
        n /= 10;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, n, m, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        ans = 0;
        while(1)
        {
            m = call(n);

            if(m == n)
                break;

            n = m;
            ans++;
        }

        cout << ans << "\n";
    }
}

