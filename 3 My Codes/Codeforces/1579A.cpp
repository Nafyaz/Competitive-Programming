#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, a, b, c;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        a = b = c = 0;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A')
                a++;
            if(s[i] == 'B')
                b++;
            if(s[i] == 'C')
                c++;
        }

        if(a+c == b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
