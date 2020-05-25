#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, k, i, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ans = n*(n+1)/2;
        n /= k;
        while(n)
        {
            ans -= n*(n+1)/2*k;
            ans += n*(n+1)/2;
            n /= k;
        }
        cout << ans << endl;
    }
}
