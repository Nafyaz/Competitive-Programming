#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;
    string s, ans;
    int freq[26] = {0};

    cin >> n >> k >> s;

    for(i = 0; i < n; i++)
        freq[s[i]-'a']++;


    for(i = 0; i < 26; i++)
    {
        while(freq[i] && k)
        {
            freq[i]--;
            k--;
        }
    }

    for(i = n-1; i >= 0; i--)
    {
        if(freq[s[i]-'a'])
        {
            ans.push_back(s[i]);
            freq[s[i]-'a']--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans;
}
