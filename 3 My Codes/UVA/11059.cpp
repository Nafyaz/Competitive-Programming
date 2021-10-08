#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll i, j, k, n, s[20], caseno = 0, ans, mul;

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
            cin >> s[i];

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = i; j <= n; j++)
            {
                mul = 1;
                for(k = i; k <= j; k++)
                    mul *= s[k];
                ans = max(ans, mul);
            }
        }

        cout << "Case #" << ++caseno << ": The maximum product is " << ans << ".\n\n";
    }
}
