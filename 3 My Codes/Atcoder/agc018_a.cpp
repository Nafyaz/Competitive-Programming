#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, a, mx = 0, g = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        mx = max(a, mx);
        g = __gcd(g, a);
    }

    if(k%g == 0 && mx >= k)
        cout << "POSSIBLE";
    else
        cout << "IMPOSSIBLE";
}
