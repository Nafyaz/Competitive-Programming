#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool is_pal[2003][2003];
ll endCnt[2003], pref[2003];

int main()
{
    ll i, j, len, n;
    string s;

    cin >> s;
    n = s.size();

    for(i = 1; i <= n; i++)
    {
        is_pal[i][i] = 1;
        endCnt[i]++;
        if(i < n && s[i-1] == s[i])
        {
            is_pal[i][i+1] = 1;
            endCnt[i+1]++;
        }
    }

    for(len = 3; len <= n; len++)
    {
        for(i = 1; i <= n-len+1; i++)
        {
            if(s[i-1] == s[i+len-2] && is_pal[i+1][i+len-2])
            {
                is_pal[i][i+len-1] = 1;
                endCnt[i+len-1]++;
            }
        }
    }

    for(i = 1; i <= n; i++)
        pref[i] = pref[i-1] + endCnt[i];

    ll ans = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = i; j <= n; j++)
            ans += is_pal[i][j]*pref[i-1];
    }

    cout << ans;
}
