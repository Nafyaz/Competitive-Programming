#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int T, n, i, x, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        x = a[n-1];
        ans = 0;
        for(i = n-2; i >= 0; i--)
        {
            if(a[i] > x)
            {
                ans++;
                x = a[i];
            }
        }

        cout << ans << "\n";
    }
}
