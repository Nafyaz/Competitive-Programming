#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, w, i, x, pass = 0, mn = 0, mx = 0;

    cin >> n >> w;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        pass += x;
        mn = min(mn, pass);
        mx = max(mx, pass);
    }

    if(mx - mn > w)
        cout << 0;
    else
        cout << w - mx + mn + 1;
}
