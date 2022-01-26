#include<bits/stdc++.h>
using namespace std;

string s;

bool isSmaller(int x, int y)
{
    int sumx = s[x]-'0' + s[x+1]-'0';
    int sumy = s[y]-'0' + s[y+1]-'0';

    if(sumx < 10 && sumy >= 10)
        return 1;
    else if(sumx >= 10 && sumy < 10)
        return 0;
    else if(sumx < 10 && sumy < 10)
        return 0;
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, i, mx;

    cin >> t;

    while(t--)
    {
        cin >> s;

        mx = 0;
        for(i = 1; i+2 <= s.size(); i++)
        {
            if(isSmaller(mx, i))
                mx = i;
        }

        cout << s.substr(0, mx) + to_string(s[mx]-'0'+s[mx+1]-'0') + s.substr(mx+2) << "\n";
    }
}
