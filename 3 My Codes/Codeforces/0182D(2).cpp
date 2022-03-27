#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s, t;

bool check(ll d)
{
    ll i;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != s[i%d])
            return 0;
    }

    for(i = 0; i < t.size(); i++)
    {
        if(t[i] != t[i%d])
            return 0;
    }

    for(i = 0; i < d; i++)
    {
        if(s[i] != t[i])
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, n, m, ans = 0;

    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(i = 1; i <= min(s.size(), t.size()); i++)
    {
        if(n%i == 0 && m%i == 0 && check(i))
            ans++;
    }

    cout << ans;
}
