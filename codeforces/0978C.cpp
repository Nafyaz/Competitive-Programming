#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll i, n, m, x;
    cin >> n >> m;
    ll a[n+1];
    a[0] = 0;

    for(i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = a[i-1] + x;
    }


    for(i = 0; i < m; i++)
    {
        cin >> x;
        ll pos = lower_bound(a, a+n+1, x) - a;

        cout << pos << " " << x - a[pos-1] << endl;
    }
}
