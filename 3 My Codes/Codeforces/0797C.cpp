#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int main()
{
    int i;
    char smallestRem;
    string s, t, u, temp;
    cin >> s;

    map <char, int> mp;

    for(auto it : s)
        mp[it]++;

    for(i = 0; i < s.size(); i++)
    {
        for(auto it : mp)
        {
            if(it.ss != 0)
            {
                smallestRem = it.ff;
                break;
            }
        }

        if(s[i] != smallestRem)
        {
            if(!t.empty() && t.back() <= smallestRem)
            {
                u.push_back(t.back());
                t.pop_back();
                i--;
            }
            else
            {
                t.push_back(s[i]);
                mp[s[i]]--;
            }
        }
        else
        {
            if(!t.empty() && t.back() <= smallestRem)
            {
                u.push_back(t.back());
                t.pop_back();
                i--;
            }
            else
            {
                u.push_back(s[i]);
                mp[s[i]]--;
            }
        }
    }

    while(!t.empty())
    {
        u.push_back(t.back());
        t.pop_back();
    }

    cout << u;
}
// bacb
