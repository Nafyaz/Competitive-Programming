#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

map<ll, ll> freq;
map<ll, bool> isOk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, a, sum, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
        isOk[a] = 0;
    }

    for(i = 0; i <= 32; i++)
    {
        sum = (1LL << i);

        for(auto u : freq)
        {
            if(freq.find(sum - u.ff) != freq.end())
            {
                if(u.ff != sum - u.ff || freq[sum - u.ff] > 1)
                {
                    isOk[u.ff] = 1;
                    isOk[sum - u.ff] = 1;
                }
            }
        }
    }

    ans = 0;
    for(auto u : isOk)
    {
        if(!u.ss)
            ans += freq[u.ff];
    }

    cout << ans;
}
