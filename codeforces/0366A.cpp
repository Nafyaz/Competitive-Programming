#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, b, c, d, found = 0;
    cin >> n;

    for(i = 1; i <= 4; i++)
    {
        cin >> a >> b >> c >> d;
        if(!found && min(a, b) + min(c, d) <= n)
        {
            found = 1;
            cout << i << " " << min(a, b) << " " << n - min(a, b);
        }
    }

    if(!found)
        cout << -1;
}
