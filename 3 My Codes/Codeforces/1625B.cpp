#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int a[150005];
set<int> s;
map<int, vector<int>> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        s.clear();
        mp.clear();
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);

            mp[a[i]].push_back(i);
        }

        if(s.size() == n)
        {
            cout << "-1\n";
            continue;
        }

        ans = -1;
        for(auto u : mp)
        {
            if(u.ss.size() == 1)
                continue;

            for(i = 1; i < u.ss.size(); i++)
                ans = max(ans, u.ss[i-1] + n - u.ss[i]);
        }

        cout << ans << "\n";
    }
}
