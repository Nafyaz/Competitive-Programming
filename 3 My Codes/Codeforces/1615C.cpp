#include<bits/stdc++.h>
using namespace std;

int n;

string XOR(string a, string b)
{
    string ret = "";
    for(int i = 0; i < n; i++)
        ret.push_back('0' + (a[i] != b[i]));
    return ret;
}

int main()
{
    int t, i, ans;
    string a, b, temp, xor;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        if(a == b)
        {
            cout << "0\n";
            continue;
        }

        if(a == "1" && b == "0")
        {
            cout << "-1\n";
            continue;
        }

        if(a.find('1') == string::npos)
        {
            if(b.find('1') == string::npos)
                cout << "0\n";
            else
                cout << "-1\n";
            continue;
        }

        ans = 0;
        if(count(a.begin(), a.end(), '1') == 1)
        {
            a = string(n, '1');
            ans++;
        }

        xor = XOR(a, b);


    }
}
