#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, i, n, q, c, ans;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> q >> s;
        map<char, int> mp;

        for(i = 0; i < n; i++)
            mp[s[i]]++;

        while(q--)
        {
            cin >> c;
            ans = 0;
            for(auto u : mp)
                ans += max(0, u.ss-c);

            cout << ans << endl;
        }
    }
}
