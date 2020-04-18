#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, j, a[100009], ans[100009];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        j = 0;
        for(i = n/2; i < n; i++)
        {
            ans[j] = a[i];
            j += 2;
        }

        j = 1;
        for(i = n/2-1; i >= 0; i--)
        {
            ans[j] = a[i];
            j += 2;
        }

        for(i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
