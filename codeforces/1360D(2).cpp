#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i, mx;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mx = -1;
        for(i = 1; i * i <= n; i++)
        {
            if(n%i == 0)
            {
                if(i <= k)
                    mx = max(mx, i);
                if(n/i <= k)
                    mx = max(mx, n/i);
            }
        }

        cout << n / mx << endl;
    }
}
