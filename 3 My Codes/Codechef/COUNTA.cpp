#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define total 100000

ll a[100005], b[100005];

int main()
{
    ll t, n, i, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n-1; i++)
            cin >> b[i];

        ans = 1;

        for(i = n-2; i > 0; i--)
        {
            if(b[i] == b[i-1])
                ans = (ans*(total - b[i] + 1) - 1) % mod;
        }

        ans = (2*ans*(total - b[0] + 1) - 1) % mod;

        cout << ans << "\n";
    }
}
