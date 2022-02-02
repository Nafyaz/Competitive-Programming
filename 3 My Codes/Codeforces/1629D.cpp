#include<bits/stdc++.h>
using namespace std;

bool isPal(string x)
{
    if(x.size() == 1)
        return 1;
    if(x.size() == 2 && x[0] == x[1])
        return 1;
    if(x.size() == 3 && x[0] == x[2])
        return 1;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, flag;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n;

        map<string, bool> mp, truncated;

        flag = 0;
        for(i = 0; i < n; i++)
        {
            cin >> s;

            if(flag || isPal(s))
            {
                flag = 1;
                continue;
            }

            mp[s] = 1;
            if(s.size() == 3)
                truncated[s.substr(0, 2)] = 1;

            reverse(s.begin(), s.end());

            if((mp.find(s) != mp.end()) || (s.size() == 3 && mp.find(s.substr(0, 2)) != mp.end()))
                flag = 1;

            else if(s.size() == 2 && truncated.find(s) != truncated.end())
                flag = 1;

        }

        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
