#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, a, x, ans, prev;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;

        cin >> prev;

        for(i = 1; i < n; i++)
        {
            cin >> a;
            if(a < prev)
            {
                x = log2(prev - a);

                ans = max(ans, x+1);

                a = prev;
            }

            prev = a;
        }
        cout << ans << endl;
    }
}
