#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;
    string s;

    cin >> s;
    n = s.size();

    vector<int> xIdx;
    for(i = 0; i < n; i++)
    {
        if(s[i] == 'x')
            xIdx.push_back(i);
    }

    if(xIdx.empty())
    {
        cout << 0;
        return 0;
    }

    int pow;
    int coeff[100] = {0};

    for(auto u : xIdx)
    {
        if(u+1 == n || s[u+1] == '+' || s[u+1] == '-')
            pow = 1;
        else if(u+2 == n || s[u+2] == '+' || s[u+2] == '-')
            pow = s[u+1] - '0';
        else
            pow = 10*(s[u+1] - '0') + s[u+2] - '0';

        if(u == 0 || s[u-1] == '+')
            coeff[pow] = 1;
        else if(s[u-1] == '-')
            coeff[pow] = -1;
        else if(u-1 == 0 || s[u-2] == '+')
            coeff[pow] = s[u-1] - '0';
        else if(s[u-2] == '-')
            coeff[pow] = - s[u-1] + '0';
        else if(u-2 == 0 || s[u-3] == '+')
            coeff[pow] = 10*(s[u-2] - '0') + s[u-1] - '0';
        else
            coeff[pow] = -10*(s[u-2] - '0') - s[u-1] + '0';
    }

//    for(i = 6; i >= 0; i--)
//        cout << "i: " << i << "; coeff: " << coeff[i] << "\n";
//    cout << to_string(-10) << "\n";

    s = "";
    for(i = 99; i >= 1; i--)
    {
        if(coeff[i])
        {
            if(coeff[i] > 0)
                s += "+";
            s += to_string(coeff[i]*i);
            if(i > 1)
                s += "x";
            if(i > 2)
                s += to_string(i-1);
        }
    }

    if(s[0] == '+')
        cout << s.substr(1);
    else
        cout << s;
}

