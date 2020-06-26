#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, x, i, a[100009], ans, rem;

int main()
{
    cin >> t;
    while(t--)
    {
        ans = rem = 0;
        cin >> n >> x;
        for(i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n, greater<ll>());
        for(i = 0; i < n; i++)
        {
            if(a[i] >= x)
            {
                ans++;
                rem += a[i] - x;
            }
            else if(rem >= x - a[i])
            {
                ans++;
                rem -= x - a[i];
            }
        }

        cout << ans << endl;
    }
}
