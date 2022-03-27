#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, a[1003];

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        cout << a[n-2] + a[n-1] << "\n";
    }
}
