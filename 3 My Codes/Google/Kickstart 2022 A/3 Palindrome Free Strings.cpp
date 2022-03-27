#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
string s, t;

bool check()
{
    ll len = t.size();

    if(len >= 5 && t[len-1] == t[len-5] && t[len-2] == t[len-4])
        return 1;
    if(len >= 6 && t[len-1] == t[len-6] && t[len-2] == t[len-5] && t[len-3] == t[len-4])
        return 1;

    return 0;
}

bool func(ll i)
{
//    cout << t << "\n";
    if(i == n)
        return 1;

    if(s[i] != '?')
    {
        t.push_back(s[i]);
        if(check() || !func(i+1))
        {
            t.pop_back();
            return 0;
        }
        else
            return 1;
    }

    t.push_back('0');
    if(!check() && func(i+1))
        return 1;
    else
        t.pop_back();

    t.push_back('1');
    if(!check() && func(i+1))
        return 1;
    else
        t.pop_back();

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        t = "";
        cout << "Case #" << ++caseno << ": " << (func(0)? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
