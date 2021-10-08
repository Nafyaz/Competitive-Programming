#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, n, i, j, a;

    cin >> t;

    while(t--)
    {
        cin >> n;

        vector<pair<int, int>> v;
        vector<pair<pair<int, int>, int>> ans;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back({a, i});
        }

        sort(v.begin(), v.end());

//        for(j = 0; j < n; j++)
//            cout << v[j].ff << " " << v[j].ss << "; ";
//        cout << "\n";

        for(i = 0; i < n; i++)
        {
            if(i == v[i].ss)
                continue;

            ans.push_back({{i+1, v[i].ss+1}, v[i].ss-i});
            for(j = 0; j < n; j++)
            {
                if(i <= v[j].ss && v[j].ss < v[i].ss)
                    v[j].ss ++;
            }
            v[i].ss = i;

//            for(j = 0; j < n; j++)
//                cout << v[j].ff << " " << v[j].ss << "; ";
//            cout << "\n";
        }

        cout << ans.size() << "\n";
        for(auto u : ans)
            cout << u.ff.ff << " " << u.ff.ss << " " << u.ss << "\n";
    }
}
