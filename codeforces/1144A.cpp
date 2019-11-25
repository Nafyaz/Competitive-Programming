#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, freq[26], ans;
    string s;
    cin >> t;
    while(t--)
    {
        ans = 1;
        memset(freq, 0, sizeof(freq));
        cin >> s;
        for(auto u : s)
        {
            freq[u - 'a'] ++;
            if(freq[u - 'a'] > 1)
            {
                ans = 0;
                break;
            }
        }

        if(!ans)
        {
            cout << "No" << endl;
            continue;
        }

        sort(s.begin(), s.end());

        s[s.size()-1] - s[0] + 1 == s.size()? cout << "Yes" : cout << "No";
        cout << endl;
    }
}
