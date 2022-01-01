#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, l[3];

    cin >> t;

    while(t--)
    {
        cin >> l[0] >> l[1] >> l[2];

        sort(l, l+3);

        if(l[2] == l[0] + l[1])
            cout << "YES\n";
        else if(l[0] == l[1] && l[2]%2 == 0)
            cout << "YES\n";
        else if(l[1] == l[2] && l[0]%2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
