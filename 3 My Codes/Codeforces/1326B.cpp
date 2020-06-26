#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, i;
    cin >> n;
    ll a[n+1], b[n+1], x[n+1];

    x[0] = 0;

    for(i = 0; i < n; i++)
    {
        cin >> b[i];
        a[i] = b[i] + x[i];
        x[i+1] = max(x[i], a[i]);
    }

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
