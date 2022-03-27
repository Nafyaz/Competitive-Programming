#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, odd, even;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        odd = even = 0;
        for(i = 0; i < s.size(); i++)
        {
            if((s[i] - '0')%2 == 1)
                odd++;
            else
                even++;
        }

        if((s.back()-'0')%2 == 0 && even == 1)
            cout << "NO\n";
        else if((s.back()-'0')%2 == 1 && odd == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
