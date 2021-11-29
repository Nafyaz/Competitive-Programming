#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, n, i, cnt, sum;

    cin >> t;

    while(t--)
    {
        cin >> n;

        cnt = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            while(a[i]%2 == 0)
            {
                a[i] /= 2;
                cnt++;
            }
        }

        sort(a, a+n);

        while(cnt)
        {
            a[n-1] *= 2;
            cnt--;
        }

        sum = 0;

        for(i = 0; i < n; i++)
            sum += a[i];

        cout << sum << "\n";
    }
}
