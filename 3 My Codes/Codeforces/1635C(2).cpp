#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        if(is_sorted(a+1, a+n+1))
        {
            cout << "0\n";
            continue;
        }

        if(a[n-1] > a[n] || a[n] < 0)
        {
            cout << "-1\n";
            continue;
        }

        cout << n-2 << "\n";
        for(i = n-2; i >= 1; i--)
            cout << i << " " << n-1 << " " << n << "\n";
    }
}
