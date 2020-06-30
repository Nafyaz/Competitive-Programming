#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, o, z;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        o = z = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                o++;
            else
                z++;
        }

        if(min(o, z)%2 == 1)
            cout << "DA\n";
        else
            cout << "NET\n";
    }
}
