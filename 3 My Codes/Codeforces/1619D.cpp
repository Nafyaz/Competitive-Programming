#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<pair<int, int>> v[100005];
int prefixMinLeft[100005], prefixMinRight[100005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.ff == b.ff)
        return a.ss > b.ss;
    return a.ff > b.ff;
}

int main()
{
    int t, n, m, ans, i, j;

    cin >> t;

    while(t--)
    {
        cin >> m >> n;

        int p[m][n];

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                cin >> p[i][j];
        }

        set<int> s;
        for(j = 0; j < n; j++)
        {
            v[j].clear();
            for(i = 0; i < m; i++)
                v[j].push_back({p[i][j], i});

            sort(v[j].begin(), v[j].end(), cmp);

            s.insert(v[j][0].ss);
        }

        cout << "v[j]:\n";
        for(j = 0; j < n; j++)
        {
            for(auto u : v[j])
                cout << u.ff << ", " << u.ss << "; ";
            cout << "\n";
        }

        for(j = 0; j < n; j++)
        {
            if(!j)
                prefixMinLeft[j] = v[j][0].ff;
            else
                prefixMinLeft[j] = min(prefixMinLeft[j-1], v[j][0].ff);
        }

        for(j = n-1; j >= 0; j--)
        {
            if(j == n-1)
                prefixMinRight[j] = v[j][0].ff;
            else
                prefixMinRight[j] = min(prefixMinRight[j+1], v[j][0].ff);
        }

        if(s.size() < n)
        {
            cout << prefixMinLeft[n-1] << "\n";
            continue;
        }

        cout << "s:\n";
        for(auto u : s)
            cout << u << " ";
        cout << "\n";

        ans = 0;
        for(j = 0; j < n; j++)
        {
            for(i = 1; i < m && s.find(v[j][i].ss) == s.end(); i++);

            cout << "j: " << j << ", i: " << i << "\n";

            int mn = INT_MAX;
            if(j > 0)
                mn = min(mn, prefixMinLeft[j-1]);
            mn = min(mn, v[j][i].ff);
            if(j+1 < n)
                mn = min(mn, prefixMinRight[j+1]);

            ans = max(ans, mn);
        }

        cout << ans << "\n";
    }
}
