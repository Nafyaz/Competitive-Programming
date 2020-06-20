#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod(ll a, ll b, ll m)
{
    if(b == 0)
        return 1%m;
    ll ret = bigmod(a, b/2, m);
    ret = (ret * ret) % m;
    if(b&1)
        ret = (ret * a) % m;
    return ret;
}

int main()
{
//    freopen("calc.in", "r", stdin);
//    freopen("calc.out", "w", stdout);

    ll n, k, i;
    cin >> n >> k;

    if(k == 1)
        cout << 0;
    else
    {
        map<ll, ll> mp;
        ll st = 0, clen, p;
        for(i = 1; mp.find(i) == mp.end(); i = (i<<1)%k)
        {
            mp[i] = st++;
        }

        clen = st - mp[i];
        st = mp[i];
        cout << st << " " << clen << endl;

        if(n < st)
        {
            cout << bigmod(2, )
        p = bigmod(2, (n-st))
        p = bigmod(2, st + n-st, clen);

        cout << (bigmod(2, p, k) + 1) % k;
    }

}
