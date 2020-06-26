#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int caseno = 0, i, j, n;
    char arr[70];

    j = 0;
    for(i = '0'; i <= '9'; i++)
        arr[j++] = i;
    for(i = 'A'; i <= 'Z'; i++)
        arr[j++] = i;
    for(i = 'a'; i <= 'z'; i++)
        arr[j++] = i;
    int totchar = j;

    string s[109], t[109];
    while(1)
    {
        cin >> n;
        if(!n)
            break;

        for(i = 0; i < n; i++)
            cin >> s[i] >> t[i];

        map<char, int> mp;
        bool flag = 1;
        cout << "Case " << ++caseno << ": ";
        for(i = 0; i < n; i++)
        {
            if(!flag)
                break;
            if(s[i].size() < t[i].size())
            {
                flag = 0;
                break;
            }

            if(t[i].size() > 2 && s[i].size() > t[i].size() && s[i][t[i].size()-1] != 1)
                mp[s[i][t[i].size()-1]] = -1;
            else if(t[i].size() > 2 && s[i].size() > t[i].size())
            {
                flag = 0;
                break;
            }

            for(j = 1; j < s[i].size()-1; j++)
            {
                if(!flag)
                    break;
                if(s[i][j] != t[i][j])
                {
                    if(mp[s[i][j]] == 1)
                    {
                        flag = 0;
                        break;
                    }
                    else
                    {
                        mp[s[i][j]] = -1;
                        break;
                    }
                }
                if(mp[s[i][j]] == -1)
                {
                    flag = 0;
                    break;
                }

                mp[s[i][j]] = 1;
            }
        }

        int totalpos = 0;
        for(auto u : mp)
        {
            if(u.ss == 1 && u.ff !='"')
                totalpos++;
        }
        if(totalpos == 0)
            flag = 0;

        if(!flag)
            cout << "I_AM_UNDONE" << endl;
        else
        {
            cout << '[';
            for(i = 0; i < totchar; i++)
            {
                if(mp[arr[i]] == 0)
                    cout << arr[i];
                else
                    break;
            }

            for(auto u : mp)
            {
                if(u.ss == 1 && u.ff != '"')
                    cout << u.ff;
            }

            cout << ']' << endl;
        }
    }
}
