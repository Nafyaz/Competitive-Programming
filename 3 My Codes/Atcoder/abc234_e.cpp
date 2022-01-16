#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d, i;
    string s, t, ans;
    char c;
    bool bigger;

    cin >> s;

    for(d = -9; d <= 9; d++)
    {
        t = s[0];
        bigger = 0;
        for(i = 1; i < s.size(); i++)
        {
            c = t.back() + d;
            if(c >= '0' && c <= '9' && (bigger || c >= s[i]))
            {
                t.push_back(c);
                if(c > s[i])
                    bigger = 1;
            }
            else
                break;
        }

        if(i < s.size())
            continue;

        cout << t;
        return 0;
    }

    for(d = -9; d <= 9; d++)
    {
        t = s[0] + 1;
        bigger = 1;
        for(i = 1; i < s.size(); i++)
        {
            c = t.back() + d;
            if(c >= '0' && c <= '9' && (bigger || c >= s[i]))
            {
                t.push_back(c);
                if(c > s[i])
                    bigger = 1;
            }
            else
                break;
        }

        if(i < s.size())
            continue;

        cout << t;
        return 0;
    }
}
