#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool call(ll a, ll b, ll x)
{
    if(x == a || x == b)
        return 1;

    if(x > a)
        return 0;
    if(x < b)
        return call(b, a%b, x);

    if(b && (a - x) % b == 0)
        return 1;
    return 0;
}

int main()
{
    ll t, a, b, x;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> x;

        if(a < b)
            swap(a, b);

        cout << (call(a, b, x)? "YES\n" : "NO\n");
    }
}
