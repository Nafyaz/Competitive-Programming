#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, j, swapCnt;
    string s, t;

    cin >> T;

    while(T--)
    {
        cin >> n >> s >> t;

        vector<pair<int, int>> ans;

        for(i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                for(j = i+1; j < n; j++)
                {
                    if(s[i] == s[j])
                    {
                        swap(t[i], s[j]);
                        ans.push_back({j+1, i+1});
                        break;
                    }
                    if(s[i] == t[j])
                    {
                        swap(s[j], t[j]);
                        ans.push_back({j+1, j+1});

                        swap(t[i], s[j]);
                        ans.push_back({j+1, i+1});
                        break;
                    }
                }
            }
        }

        if(s != t || ans.size() >= 2*n)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
            cout << ans.size() << "\n";
            for(auto u : ans)
                cout << u.first << " " << u.second << "\n";
        }
    }
}
