#include<bits/stdc++.h>
using namespace std;

string clear_zero(string s)
{
    int i;
    string ret;
    for(i = 0; s[i] == '0'; i++);

    ret = s.substr(i, s.size() - i);
    return ret;
}

int main()
{
    int t, carry, i, x, y;
    string a, b, ans;
    cin >> t;
    while(t--)
    {
        ans = "";
        cin >> a >> b;

        a = clear_zero(a);
        b = clear_zero(b);

        carry = 0;
        for(i = 0; i < a.size() || i < b.size(); i++)
        {
            x = y = 0;
            if(i < a.size())
                x = a[i] - '0';
            if(i < b.size())
                y = b[i] - '0';

            carry += x + y;
            char temp = '0' + carry%10;
            ans = ans + temp;
            carry /= 10;
        }

        ans = clear_zero(ans);
        char temp = '0' + carry%10;
        if(temp != '0')
            ans = ans + temp;

        cout << ans << "\n";
    }
}
