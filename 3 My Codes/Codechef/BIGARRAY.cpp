#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, s, sum, ans;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        sum = n*(n+1)/2;

        ans = sum - s;

        if(1 <= ans && ans <= n)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
}
