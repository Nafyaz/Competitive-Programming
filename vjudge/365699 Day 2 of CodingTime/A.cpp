#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[100009], b[100009];

int main()
{
    ll i, ans = 0, x;
    cin >> n;
    for(i = 0; i <= n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    for(i = 0; i < n; i++)
    {
        x = min(a[i], b[i]);
        ans += x;
        b[i] -= x;
        a[i] -= x;

        x = min(a[i+1], b[i]);
        ans += x;
        b[i] -= x;
        a[i+1] -= x;
    }

    cout << ans;
}
