#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, ans;
    string s;
    cin >> s;

    int x = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(i&1)
            x += s[i] == '0';
        else
            x += s[i] == '1';
    }

    ans = x;
    x = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(i&1)
            x += s[i] == '1';
        else
            x += s[i] == '0';
    }

    cout << min(x, ans);
}
