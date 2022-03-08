#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll freq[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, i, j, a, mx, ans;

    cin >> n >> k;

    mx = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
        mx = max(mx, a);
    }

    ans = 0;
    if(k == 0)
    {
        for(i = 0; i <= mx; i++)
            ans += freq[i]*(freq[i] - 1) / 2;

        cout << ans;
        return 0;
    }

    for(i = 0; i <= mx; i++)
    {
        for(j = i+1; j <= mx; j++)
        {
            if(__builtin_popcountll(i^j) == k)
                ans += freq[i] * freq[j];
        }
    }

    cout << ans;
}
