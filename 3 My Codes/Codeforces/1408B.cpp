#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i, a[102], distinct;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        distinct = 0;
        a[0] = -1;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
            distinct += (a[i] != a[i-1]);
        }

        if(distinct <= k)
            cout << "1\n";
        else if(k == 1)
            cout << "-1\n";
        else
            cout << 1 + ((distinct - k) + k - 2)/(k - 1) << "\n";
    }
}
