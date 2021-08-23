#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, d, i, a[100005], ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> d;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);

        ans = 0;
        for(i = n-1; i > 0; i--)
        {
            if(a[i] - a[i-1] < d)
            {
                ans += a[i] + a[i-1];
                i--;
            }
        }

        cout << ans << "\n";
    }
}
