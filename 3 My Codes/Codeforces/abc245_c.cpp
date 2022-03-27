#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
ll a[200005], b[200005];

bool isPossible(ll prev, ll i)
{
    if(i == n)
        return 1;

    bool ret = 0;
    if(abs(a[i] - prev) <= k)
        ret |= isPossible(a[i], i+1);
    if(ret == 0 && abs(b[i] - prev) <= k)
        ret |= isPossible(b[i], i+1);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    for(i = 1; i < n; i++)
    {
        if(abs(a[i-1] - a[i]) > k && abs(a[i-1] - b[i]) > k && abs(b[i-1] - a[i]) > k && abs(b[i-1] - b[i]) > k)
        {
            cout << "No\n";
            return 0;
        }
    }

    if(isPossible(a[0], 1) || isPossible(b[0], 1))
        cout << "Yes\n";
    else
        cout << "No\n";
}
