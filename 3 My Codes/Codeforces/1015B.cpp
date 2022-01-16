#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    string s, t;

    cin >> n >> s >> t;

    string stemp = s, ttemp = t;
    sort(stemp.begin(), stemp.end());
    sort(ttemp.begin(), ttemp.end());

    if(stemp != ttemp)
    {
        cout << -1;
        return 0;
    }

    vector<int> ans;
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(t[i] == s[j])
                break;
        }

        for(; j > i; j--)
        {
            ans.push_back(j);
            swap(s[j-1], s[j]);
        }
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u << " ";
}
