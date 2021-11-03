#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s2l(string s)
{
    ll ret = 0, i;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != '.')
            ret = ret*10 + (s[i] - '0');
    }

    if(s.size() < 3 || (s.size() >= 3 && s[s.size()-3] != '.'))
        ret *= 100;

    return ret;
}

string ll2s(ll ans)
{
    string ret;
    ll dollar = ans/100, cent = ans%100;

    if(!dollar)
        ret += '0';

    for(int i = 0; dollar; i++, dollar/=10)
    {
        if(i != 0 && i%3 == 0)
            ret = '.' + ret;
        ret = (char)(dollar%10 + '0') + ret;
    }

    if(cent)
        ret = ret + '.' + (char)(cent/10 + '0') + (char)(cent%10 + '0');

    return ret;
}

int main()
{
    ll i;
    string s, p;
    vector<string> v;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
            p += s[i];
        else
        {
            if(p != "")
                v.push_back(p);
            p = "";
        }
    }
    v.push_back(p);

    ll ans = 0, x;
    for(auto u : v)
    {
        x = 0;
        x += s2l(u);

        ans += x;
    }

    cout << ll2s(ans);
}
