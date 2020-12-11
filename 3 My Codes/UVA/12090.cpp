#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ans;

ll func(ll n, ll b)
{
    ll ret = 0;
    while(n%b == 0)
    {
        n /= b;
        ret++;
    }

    return ret;
}

int main()
{
    ll n, i;
    while(cin >> n)
    {
        if(!n)
            break;

        if(n == 0 || n == 1)
        {
            cout << n << " 0\n";
            continue;
        }

        ans = func(n, n);

        for(i = 2; i * i < n; i++)
        {
            if(n%i == 0)
                ans += func(n, i) + func(n, n/i);
//            cout << i << " " << ans << "\n";
        }

        if(i * i == n)
            ans += func(n, i);

//        ans = 0;
//        for(i = 2; i <= n; i++)
//            ans += func(n, i);

        cout << n << " " << ans << "\n";
    }
}
