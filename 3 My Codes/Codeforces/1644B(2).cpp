#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, i, a[51];

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n == 3)
        {
            cout << "3 2 1\n";
            cout << "1 3 2\n";
            cout << "3 1 2\n";
            continue;
        }

        for(i = 1; i <= n; i++)
            a[i] = i;

        reverse(a+1, a+n+1);
        k = n;
        while(k--)
        {
            for(i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            rotate(a+1, a+2, a+n+1);
        }
    }
}
