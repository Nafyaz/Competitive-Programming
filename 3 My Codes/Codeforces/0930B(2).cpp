#include<bits/stdc++.h>
using namespace std;

vector<int> idx[26];
int cnt[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, n, distinct;
    string s;

    cin >> s;
    n = s.size();

    for(i = 0; i < n; i++)
        idx[s[i]-'a'].push_back(i);

    int ans = 0;
    for(i = 0; i < 26; i++)
    {
        int mx = 0;

        for(j = 0; j < n; j++)
        {
            memset(cnt, 0, sizeof cnt);
            distinct = 0;

            for(auto u : idx[i])
            {
                cnt[s[(u+j)%n] - 'a']++;

                if(cnt[s[(u+j)%n] - 'a'] == 1)
                    distinct++;
                else if(cnt[s[(u+j)%n] - 'a'] == 2)
                    distinct--;
            }

            mx = max(mx, distinct);
        }

        ans += mx;
    }
    cout << (double)ans/n;
}
