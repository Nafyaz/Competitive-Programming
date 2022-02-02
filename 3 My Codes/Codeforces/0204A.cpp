#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isEqual(ll x)
{
    ll lastDigit = x%10;
    while(x >= 10)
        x /= 10;

    return (x == lastDigit);
}

int main()
{
    ll l, r, ans = 0;

    cin >> l >> r;

    while(l%10 && l <= r)
    {
        if(isEqual(l))
            ans++;
        l++;
    }

    while(r%10 && l <= r)
    {
        if(isEqual(r))
            ans++;
        r--;
    }

    ans += (r-l)/10;

    cout << ans;
}
