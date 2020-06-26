#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, c, m, x, team, l, r, mid;
    cin >> T;
    while(T--)
    {
        cin >> c >> m >> x;

        team = min(c, m);
        if(c+m+x >= 3*team)
            cout << team << endl;
        else
            cout << (c + m + x)/3 << endl;
    }
}
