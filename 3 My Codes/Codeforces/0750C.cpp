#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll c[200005];
ll d[200005];

ll call(ll r)
{
    ll i;
    for(i = 0; i < n; i++)
    {
        if(r < 1900 && d[i] == 1)
            return 1;
        if(r >= 1900 && d[i] == 2)
            return -1;

        r += c[i];
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, d1Cnt = 0, d2Cnt = 0, flag = 1, totalChange = 0;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> c[i] >> d[i];

        if(i && d[i-1] == 1 && c[i-1] >= 0 && d[i] == 2)
            flag = 0;
        if(i && d[i-1] == 2 && c[i-1] <= 0 && d[i] == 1)
            flag = 0;

        totalChange += c[i];

        d1Cnt += (d[i] == 1);
        d2Cnt += (d[i] == 2);
    }

    if(!flag)
    {
        cout << "Impossible";
        return 0;
    }
    if(d2Cnt == 0)
    {
        cout << "Infinity";
        return 0;
    }
//    if(d1Cnt == 0)
//    {
//        cout << 1899 + c[n-1];
//        return 0;
//    }

    ll ans = INT_MAX, l, r, mid, update;
    l = INT_MIN, r = INT_MAX;
    while(l <= r)
    {
        mid = (l+r)/2;

        update = call(mid);

        if(update == 1)
            l = mid + 1;
        else if(update == 0)
        {
            l = mid + 1;
            ans = mid + totalChange;
        }
        else if(update == -1)
            r = mid - 1;
    }

    if(ans == INT_MAX)
        cout << "Impossible";
    else
        cout << ans;
}
