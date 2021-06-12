#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseno = 0, n, x, mx;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mx = -1;

        while(n--)
        {
            cin >> x;
            mx = max(x, mx);
        }

        cout << "Case " << ++caseno << ": " << mx << "\n";
    }


}
