#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i, x = 0, ans = 0;

    cin >> s;

    for(i = 0; i < (int)s.size(); i++)
    {
        if(s[i] == '(')
            x++;
        else if(s[i] == ')' && x > 0)
        {
            x--;
            ans += 2;
        }
    }

    cout << ans;
}
