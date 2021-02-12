#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, a, b, c, d, caseno = 0;

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c;

        d = __gcd(a, b);

        cout << "Case " << ++caseno << ": " << (c%d? "No\n" : "Yes\n");
    }
}
