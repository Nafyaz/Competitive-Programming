#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, colonIdx;
    string s, ans;

    cin >> n;

    while(n--)
    {
        cin >> s;

        ans="0000:0000:0000:0000:0000:0000:0000:0000";

        colonIdx = 4;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == ':')
            {
                for(j = i-1; j >= 0 && s[j] != ':'; j--)
                    ans[colonIdx - (i-j)] = s[j];

                colonIdx += 5;
            }
            if(s[i] == ':' && i+1 < s.size() && s[i+1] == ':')
                break;

//            cout << ans << "\n";
        }

        if(i == s.size())
        {
            for(j = i-1; j >= 0 && s[j] != ':'; j--)
                ans[colonIdx - (i-j)] = s[j];

            cout << ans << "\n";
            continue;
        }

        colonIdx = 39;
        j = s.size();
        for(i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == ':' && i >= 1 && s[i-1] == ':')
                break;

            if(s[i] == ':')
            {
                colonIdx -= 5;
                j = i;
            }
            else
                ans[colonIdx - (j-i)] = s[i];
        }

        cout << ans << "\n";
    }
}
