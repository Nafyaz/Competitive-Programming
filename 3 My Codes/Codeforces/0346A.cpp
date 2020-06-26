#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, g = 0, mx = 0, x;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        mx = max(mx, x);
        g = __gcd(g, x);
    }

    int cnt = mx/g;

    cout << ((cnt-n)&1? "Alice" : "Bob") << endl;
}

