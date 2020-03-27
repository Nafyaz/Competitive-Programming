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
    int i;
    char j;
    string s, x, y;
    cin >> s;
    for(i = 0; i <= s.size(); i++)
    {
        x = s.substr(0, i);
        y = s.substr(i, s.size() - i);
        for(j = 'a'; j <= 'z'; j++)
        {
            if(pal(x+j+y))
            {
                cout << x+j+y;
                return 0;
            }
        }
    }

    cout << "NA";
}

