#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, n, x, a, sum, mn, mx, infected;

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        sum = infected = 0;
        mn = INT_MAX;
        mx = INT_MIN;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;

            infected += (a == x);

            mn = min(mn, a);
            mx = max(mx, a);
        }

        if(mn == mx && x == mn)
            cout << "0\n";
        else if(infected || sum % n == 0 && sum/n == x)
            cout << "1\n";
        else
            cout << "2\n";
    }
}
