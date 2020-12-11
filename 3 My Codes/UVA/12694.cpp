#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

bool cmp(pii a, pii b)
{
    return a.ss < b.ss;
}

int main()
{
    int t, n, a, b, ans, prev_ss;
    vector<pii> v;
    cin >> t;
    while(t--)
    {
        v.clear();
        while(cin >> a >> b)
        {
            if(!a && !b)
                break;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end(), cmp);

        ans = prev_ss = 0;
        for(auto u : v)
        {
            if(prev_ss <= u.ff)
            {
                ans++;
                prev_ss = u.ss;
            }
        }

        cout << ans << "\n";
    }
}
