#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, i, n, t[200009], c[200009], ans, x;
    cin >> q;

    while(q--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> t[i];
            c[i] = 0;
        }

        ans = 0;
        for(i = 0; i < n-1; i++)
        {
            if(i == 0)
            {
                ans++;
                c[i] = 1;
                continue;
            }
            if(t[i-1] == t[i])
                c[i] = c[i-1];
            else
                c[i] = c[i-1]%2 + 1;
            ans = max(ans, c[i]);
        }

        if(t[n-2] == t[n-1])
            c[n-1] = c[n-2];
        else if(t[0] == t[n-1])
            c[n-1] = c[0];
        else
            c[n-1] = 3;

        ans = max(ans, c[n-1]);

        cout << ans << endl;
        for(i = 0; i < n; i++)
            cout << c[i] << " ";
        cout << endl;
    }
}
