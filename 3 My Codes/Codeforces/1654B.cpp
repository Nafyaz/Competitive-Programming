#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        ll freq[26] = {0};

        for(i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        for(i = 0; i < s.size(); i++)
        {
            if(freq[s[i]-'a'] > 1)
                freq[s[i]-'a']--;
            else
                break;
        }

        cout << s.substr(i) << "\n";
    }
}
