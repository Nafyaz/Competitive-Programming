#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, i, posa, posb, sa, sb;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'A')
                posa = i;
            if(s[i] == 'B')
                posb = i;
        }

        cin >> sa >> sb;

        if((posb - posa) % (sa + sb) == 0)
            cout << "unsafe\n";
        else
            cout << "safe\n";
    }
}
