#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, ans = 0, f = 0;

    cin >> n;

    for(i = 1; f <= n; i++)
    {
        f = f + 3*i - 1;
        if((n-f)%3 == 0)
            ans++;
    }

    cout << ans;
}
