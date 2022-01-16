#include<bits/stdc++.h>
using namespace std;

int func(string s, string t)
{
    if(t == "00" && count(s.begin(), s.end(), '0') < 2)
        return INT_MAX;
    if(s.find(t[0]) == -1 || s.find(t[1]) == -1)
        return INT_MAX;

    int i, ret = 0;

    for(i = s.size()-1; i >= 0 && s[i] != t[1]; i--);
    for(; i+1 < s.size(); i++)
    {
        swap(s[i], s[i+1]);
        ret++;
    }

    for(i = s.size()-2; i >= 0 && s[i] != t[0]; i--);
    for(; i+2 < s.size(); i++)
    {
        swap(s[i], s[i+1]);
        ret++;
    }

    for(i = 0; i < s.size()-2 && s[i] == '0'; i++);

    ret += i;

    return ret;
}

int main()
{
    string n;

    cin >> n;

    int ans = min({func(n, "00"), func(n, "25"), func(n, "50"), func(n, "75")});

    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}
