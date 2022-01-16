#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, cap;
ll s[1000006];
ll pre[1000006];

pair<bool, ll> call(ll mid)
{
    pair<bool, ll> ret = {0, -1};

    for(ll i = mid; i <= n; i++)
    {
        if(pre[i] - pre[i-mid] > cap)
            return {0, -1};
        else if(i+1 <= n && pre[i+1] - pre[i-mid] > cap && ret.ss == -1)
            ret.ss = i-mid+1;
    }

    ret.ff = 1;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, low, high, mid, r, l;
    string c;

    cin >> n >> c;

    switch(c.back())
    {
    case 'M':
        cap = stoll(c.substr(0, c.size()-1));
        break;
    case 'G':
        cap = stoll(c.substr(0, c.size()-1)) * 1024;
        break;
    case 'T':
        cap = stoll(c.substr(0, c.size()-1)) * 1048576;
        break;
    }

    for(i = 1; i <= n; i++)
    {
        cin >> s[i];
        pre[i] = pre[i-1] + s[i];
//        cout << pre[i] << " ";
    }
//    cout << "\n";

    low = 0;
    high = n;
    r = 0;
    l = -1;

//    pair<ll, ll> p = call(2);
//    cout << p.ff << " " << p.ss << "\n";

    while(low <= high)
    {
        mid = (low + high) / 2;

//        cout << mid << "\n";

        pair<ll, ll> p = call(mid);
        if(p.ff)
        {
            r = mid;
            l = p.ss;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << r << " " << l;
}

