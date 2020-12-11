#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, ans;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;

        for(i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
    }
}
