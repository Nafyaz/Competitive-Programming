#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, i, a[200009], b[200009], pos = 0, neg = 0, zer = 0;

int main()
{
    vector<ll> diff;

    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    for(i = 0; i < n; i++)
    {
        diff.push_back(a[i] - b[i]);
        if(diff.back() > 0)
            pos++;
        else if(diff.back() < 0)
            neg++;
        else
            zer++;
    }

    ll x, ans = pos*(pos - 1)/2;

    ans += zer * pos;

    sort(diff.begin(), diff.end());

    for(i = 0; i < n; i++)
    {
        if(diff[i] >= 0)
            break;
        x = -diff[i];
        ans += n - (lower_bound(diff.begin(), diff.end(), x+1) - diff.begin());
    }

    cout << ans;
}
