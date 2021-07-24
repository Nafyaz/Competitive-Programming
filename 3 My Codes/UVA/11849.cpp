#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, x, ans;

    while(cin >> n >> m)
    {
        if(!n && !m)
            break;

        map<int, int> mp;

        for(i = 0; i < n+m; i++)
        {
            cin >> x;
            mp[x]++;
        }

        ans = 0;
        for(auto u : mp)
        {
            if(u.second > 1)
                ans++;
        }

        cout << ans << "\n";
    }
}
