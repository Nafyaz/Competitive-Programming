#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, caseno = 0, i, sum;
    string s, ans;
    char digit;

    cin >> t;
    while(t--)
    {
        cin >> s;

        sum = 0;
        for(i = 0; i < s.size(); i++)
            sum = (sum + s[i] - '0')%9;

        if(sum == 0)
        {
            cout << "Case #" << ++caseno << ": " << s.substr(0, 1) + '0' + s.substr(1) << "\n";
            continue;
        }

        digit = char('0' + (9 - sum));

        ans = "";
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] > digit)
            {
                ans = s.substr(0, i) + digit + s.substr(i);
                break;
            }
        }

        if(ans.empty())
            ans = s + digit;

        cout << "Case #" << ++caseno << ": " << ans << "\n";
    }
}
