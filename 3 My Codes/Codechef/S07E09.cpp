#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll T, n, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        ans = a[0]*n;

        for(i = n-1; i >= 0 && a[i] > a[0]; i--)
            ans++;

        cout << ans << "\n";
    }
}
