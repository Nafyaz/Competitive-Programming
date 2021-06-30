#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, i;

    cin >> t;

    string s;

    while(t--)
    {
        cin >> s;

        vector<int> v(26);

        for(i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
        }

        int mn = INT_MAX;
        for(auto u : v)
            mn = min(mn, u);

        cout << "Case " << ++caseno << ": " << mn << "\n";
    }
}

