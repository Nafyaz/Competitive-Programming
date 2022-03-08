//follow ecnerwala
/*
1011
11100
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> normalize(string s)
{
    ll i, x;
    vector<ll> ret;

    reverse(s.begin(), s.end());

    for(i = s.size() - 1; i >= 0; i--)
    {
        x = i;
        if(s[i] == '1')
        {
            while(!ret.empty() && ret.back() == x+1)
            {
                ret.pop_back();
                x += 2;
            }

            ret.push_back(x);
        }
    }

    return ret;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    string a, b;

    cin >> a >> b;

    vector<ll> x = normalize(a), y = normalize(b);

    if(x == y)
        cout << "=";
    else if(x > y)
        cout << ">";
    else
        cout << "<";
}
