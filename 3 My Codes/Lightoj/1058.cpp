#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, caseno = 0, n, i, j, ans;
    pair<int, int> p[1009], temp;
    vector<pair<int, int>> v;

    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> p[i].ff >> p[i].ss;

        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                temp.ff = p[i].ff + p[j].ff;
                temp.ss = p[i].ss + p[j].ss;
                v.push_back({temp});
            }
        }

        sort(v.begin(), v.end());

        ans = 0;
        j = 0;
        for(i = 1; i < (int)v.size(); i++)
        {
            if(v[i] == v[i-1])
            {
                j++;
                ans += j;
            }
            else
                j = 0;
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
