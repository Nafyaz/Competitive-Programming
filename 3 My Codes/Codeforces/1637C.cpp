#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, ones, odds, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        ans = ones = odds = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(i > 0 && i < n-1)
            {
                if(a == 1)
                    ones++;
                if(a%2 == 1)
                    odds++;

                ans += (a+1)/2;
            }
        }

        if(ones == n-2 || n == 3 && odds == 1)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}
