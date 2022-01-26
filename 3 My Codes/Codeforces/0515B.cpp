#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, b, g, i, idx;
    int ok[102] = {0};

    cin >> n >> m;

    int gcd = __gcd(n, m);

    cin >> b;
    for(i = 0; i < b; i++)
    {
        cin >> idx;
        ok[idx%gcd] = 1;
    }

    cin >> g;
    for(i = 0; i < g; i++)
    {
        cin >> idx;
        ok[idx%gcd] = 1;
    }

    for(i = 0; i < gcd; i++)
    {
        if(ok[i] == 0)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
