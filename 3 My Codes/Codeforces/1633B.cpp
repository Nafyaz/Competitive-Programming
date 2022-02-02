#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, i, o, z;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;

        o = z = 0;
        for(i = 0; i < s.size(); i++)
        {
            o += (s[i] == '0');
            z += (s[i] == '1');
        }

        if(o != z)
            cout << min(o, z) << "\n";
        else
            cout << o-1 << "\n";
    }
}
