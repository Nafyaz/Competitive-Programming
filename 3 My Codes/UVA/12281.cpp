#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, caseno = 0, n, i, d, ans, cnt, mxfib;

    vector<ll> fib;

    fib.push_back(1);
    fib.push_back(2);

    for(i = 2; fib[i-1] < 2000000009LL; i++)
        fib.push_back(fib[i-2] + fib[i-1]);

    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 1;
        for(i = 0; i < n; i++)
        {
            cin >> d;
            cnt = 0;
            while(d)
            {
                mxfib = fib[lower_bound(fib.begin(), fib.end(), d+1) - fib.begin() - 1];
                d -= mxfib;
                cnt++;
            }
            ans *= cnt;
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}

