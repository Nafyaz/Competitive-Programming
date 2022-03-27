#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, mod = 100000, ans = 1;
    string s;
    cin >> s;

    n = 10000*(s[0] - '0') + 1000*(s[2] - '0') + 100*(s[4] - '0') + 10*(s[3] - '0') + (s[1] - '0');

    for(i = 0; i < 5; i++)
        ans = (ans * n) % mod;

    cout << setfill('0') << setw(5) << ans;
}
