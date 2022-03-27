//follow lelbaba
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, a, freq[32] = {0}, ans;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        for(j = 0; a; j++, a/=2)
            freq[j] += (a&1);
    }

    ans = 0;
    for(i = 0; i < n; i++)
    {
        a = 0;
        for(j = 0; j < 32; j++)
        {
            if(freq[j])
            {
                a += (1 << j);
                freq[j]--;
            }
        }

        ans += a*a;
    }

    cout << ans;
}
