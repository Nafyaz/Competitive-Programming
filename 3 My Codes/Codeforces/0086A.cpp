#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll func(ll n)
{
    ll m = n;

    stack<ll> stk;
    while(m)
    {
        stk.push(9 - m%10);
        m /= 10;
    }

    while(!stk.empty())
    {
        m = 10*m + stk.top();
        stk.pop();
    }

    return n*m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll l, r, mid1, mid2, val1, val2, ans;

    cin >> l >> r;

    l = max(l, (ll)pow(10, (ll)(log10(r))));

    ans = 0;
    while(l <= r)
    {
        mid1 = (2*l + r)/3;
        mid2 = (l + 2*r)/3;

        val1 = func(mid1);
        val2 = func(mid2);

        if(val1 > val2)
        {
            ans = max(ans, val1);
            r = mid2 - 1;
        }
        else
        {
            ans = max(ans, val2);
            l = mid1 + 1;
        }
    }

    cout << ans;
}
