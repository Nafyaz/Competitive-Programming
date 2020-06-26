#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x, mx = -1;
    string s;

    cin >> n;
    cin >> s;

    pair<char, char> ans;
    map <pair <char, char>, int > mp;

    for(i = 1; i < n; i++)
    {
        mp[{s[i-1], s[i]}]++;
        x = mp[{s[i-1], s[i]}];

        if(x > mx)
        {
            mx = x;
            ans = {s[i-1], s[i]};
        }
    }

    cout << ans.first << ans.second;
}
