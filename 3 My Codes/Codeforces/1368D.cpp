#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, a[200005], ones[32] = {0}, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        for(j = 0; a[i]; j++, a[i]/= 2)
            ones[j] += (a[i]&1);
    }

    memset(a, 0, sizeof a);

    for(j = 0; j < 32; j++)
    {
        for(i = 0; i < ones[j]; i++)
            a[i] |= (1 << j);
    }

    ans = 0;
    for(i = 0; i < n; i++)
        ans += a[i]*a[i];

    cout << ans;
}
