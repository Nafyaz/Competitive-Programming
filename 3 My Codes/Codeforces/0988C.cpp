#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<int> v;
map<int, vector<pair<int, int>>> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int k, n, i, j, a, sum, l, r;

    cin >> k;

    for(i = 0; i < k; i++)
    {
        cin >> n;

        sum = 0;
        v.clear();
        for(j = 0; j < n; j++)
        {
            cin >> a;
            v.push_back(a);
            sum += a;
        }

        for(j = 0; j < n; j++)
            mp[sum - v[j]].push_back({i+1, j+1});
    }

    int ans_i, ans_j, ans_x, ans_y;
    ans_i = ans_j = -1;

    for(auto u : mp)
    {
        if(u.ss.size() >= 2 && u.ss[0].ff != u.ss[u.ss.size()-1].ff)
        {
            ans_i = u.ss[0].ff;
            ans_x = u.ss[0].ss;
            ans_j = u.ss[u.ss.size()-1].ff;
            ans_y = u.ss[u.ss.size()-1].ss;
        }
    }

    if(ans_i == -1 || ans_j == -1)
        cout << "NO";
    else
    {
        cout << "YES\n";
        cout << ans_i << " " << ans_x << "\n";
        cout << ans_j << " " << ans_y << "\n";
    }
}
