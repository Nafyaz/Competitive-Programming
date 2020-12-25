#include<bits/stdc++.h>
using namespace std;

string func(string s)
{
    string ret = "";

    for(auto u : s)
        ret = ret + (char)tolower(u);
    sort(ret.begin(), ret.end());

    return ret;
}

int main()
{
    string a[10009];
    string s;
    map<string, int> mp;
    int i = 0, n;

    while(cin >> s)
    {
        if(s == "#")
            break;

        a[i] = s;
        mp[func(s)]++;
        i++;
    }

    n = i;
    sort(a, a+n);

    for(i = 0; i < n; i++)
    {
        if(mp[func(a[i])] == 1)
            cout << a[i] << "\n";
    }
}
