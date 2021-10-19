#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b = 0, i, e = -1, l_zero, t_zero;
    string a_temp, d_temp, a, d, s;

    cin >> s;

    a_temp = s[0];
    for(i = 2; i < s.size(); i++)
    {
        if(s[i] == 'e')
        {
            e = i;
            continue;
        }

        if(e == -1)
            d_temp.push_back(s[i]);
        else
            b = 10*b + (s[i] - '0');
    }

    while(b--)
    {
        if(!d_temp.empty())
        {
            a_temp.push_back(d_temp[0]);
            d_temp = d_temp.substr(1);
        }
        else
            a_temp.push_back('0');
    }

    l_zero = 1;
    for(i = 0; i < a_temp.size(); i++)
    {
        if(l_zero && a_temp[i] == '0')
            continue;
        a.push_back(a_temp[i]);
        l_zero = 0;
    }

    t_zero = 1;
    for(i = d_temp.size()-1; i >= 0; i--)
    {
        if(t_zero && d_temp[i] == '0')
            continue;
        d = d_temp[i] + d;
        t_zero = 0;
    }

    if(a == "")
        cout << 0;
    else
        cout << a;

    if(d != "")
        cout << '.' << d;
}
