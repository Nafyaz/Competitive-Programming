#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a, freq[32] = {0}, ans = 0;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[__builtin_popcount(a)]++;
    }

    for(i = 0; i < 32; i++)
        ans += freq[i]*(freq[i]-1)/2;

    cout << ans;
}
