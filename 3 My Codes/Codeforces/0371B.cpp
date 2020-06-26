#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, g, i;
    cin >> a >> b;
    g = __gcd(a, b);

    a = a/g;
    b = b/g;

    int ans = 0;
    for(i = 2; i <= 5; i++)
    {
        while(a%i == 0)
        {
            a /= i;
            ans++;
        }
    }
    if(a > 1)
    {
        cout << -1;
        return 0;
    }

    for(i = 2; i <= 5; i++)
    {
        while(b%i == 0)
        {
            b /= i;
            ans++;
        }
    }

    if(b > 1)
    {
        cout << -1;
        return 0;
    }

    cout << ans;
}
