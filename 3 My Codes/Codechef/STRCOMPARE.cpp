#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, i, eq, ans;
    string a, b;

    cin >> T;

    while(T--)
    {
        cin >> n >> a >> b;

        eq = ans = 0;
        for(i = n-1; i >= 0; i--)
        {
            if(a[i] > b[i])
                eq = 1;
            else if(a[i] < b[i])
            {
                eq = -1;
                ans++;
            }
            else if(eq == -1)
                ans++;
        }

        cout << ans << "\n";
    }
}
