#include<bits/stdc++.h>
using namespace std;

bool pal(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    int T, i, j;
    string s, t, mxt;
    cin >> T;
    while(T--)
    {
        mxt = "";
        cin >> s;
        for(i = 0; i <= s.size(); i++)
        {
            for(j = i; j <= s.size(); j++)
            {
                t = s.substr(0, i) + s.substr(j, s.size() - j);
                if(pal(t) && mxt.size() < t.size())
                    mxt = t;
            }
        }
        cout << mxt << endl;
    }
}
