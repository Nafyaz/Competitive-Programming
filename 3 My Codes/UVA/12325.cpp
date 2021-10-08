#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll caseno)
{
    ll n, s1, v1, s2, v2, i, ans = 0;

    cin >> n >> s1 >> v1 >> s2 >> v2;

    if(s2 > s1)
    {
        swap(s1, s2);
        swap(v1, v2);
    }

    if(s1*s1 > n)
    {
        for(i = 0; i*s1 <= n; i++)
            ans = max(ans, i*v1 + (n-i*s1)/s2*v2);
    }
    else
    {
        for(i = 0; i < s1; i++)
            ans = max(ans, i*v2 + (n-i*s2)/s1*v1);
        for(i = 0; i < s2; i++)
            ans = max(ans, i*v1 + (n-i*s1)/s2*v2);
    }

    cout << "Case #" << caseno << ": " << ans << "\n";
}

int main()
{
    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
