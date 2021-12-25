#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> p[102];

ll deg(ll a)
{
    ll ret;
    for(ret = 0; a%3 == 0; ret++)
        a /= 3;

    return ret;
}

int main()
{
    ll n, i, a;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        p[i].ff = -deg(a);
        p[i].ss = a;
    }

    sort(p, p+n);

    for(i = 0; i < n; i++)
        cout << p[i].ss << " ";
}
