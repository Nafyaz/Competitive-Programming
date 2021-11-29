#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k, m[1003];

ll func(ll s, ll e)
{
    if(s > e)
        return 0;
    ll mnheight = INT_MAX, mnidx, i;
    for(i = s; i <= e; i++)
    {
        if(m[i] < mnheight)
        {
            mnheight = m[i];
            mnidx = i;
        }
    }

    ll x = (mnidx-s+1)*mnheight + func(mnidx+1, e);
    ll y = (e-mnidx+1)*mnheight + func(s, mnidx-1);
    if(x > y)
    {
        for(i = s; i <= mnidx; i++)
            m[i] = mnheight;
        return x;
    }
    else
    {
        for(i = mnidx; i <= e; i++)
            m[i] = mnheight;
        return y;
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> m[i];

    func(1, n);
    for(i = 1; i <= n; i++)
        cout << m[i] << " ";
}
