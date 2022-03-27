#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i;
    pair<ll, ll> a[100005];

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i+1;
    }

    sort(a, a+n);

    if(n&1)
        cout << (n+1)/2 << "\n";
    else
        cout << n/2 << "\n";
    for(i = 0; i < n; i += 2)
        cout << a[i].ss << " ";
    cout << "\n";

    cout << n/2 << "\n";
    for(i = 1; i < n; i += 2)
        cout << a[i].ss << " ";
}
