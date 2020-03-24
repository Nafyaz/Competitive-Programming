#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.ss != b.ss)
        return a.ss < b.ss;
    return a.ff > b.ff;
}

int main()
{
    int t, i, n, s, e, prev, ans;
    vector<pair<int, int> > v;
    cin >> t;
    while(t--)
    {
        cin >> n;
        v.clear();
        for(i = 0; i < n; i++)
        {
            cin >> s >> e;
            v.push_back({s, e});
        }

        sort(v.begin(), v.end(), cmp);
        prev = ans = 0;
        for(i = 0; i < n; i++)
        {
            if(v[i].ff >= prev)
            {
                ans++;
                prev = v[i].ss;
            }
        }

        cout << ans << endl;
    }
}

