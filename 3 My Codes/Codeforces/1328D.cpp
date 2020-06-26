#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, i, n, t[200009], c[200009], ans, x;
    cin >> q;

    while(q--)
    {
        cin >> n;

        ans = 1;
        for(i = 0; i < n; i++)
        {
            cin >> t[i];
            if(ans == 1 && i != 0 && t[i] != t[i-1])
                ans++;
        }

        if(n%2 == 0)
        {
            cout << ans << endl;
            for(i = 0; i < n; i++)
            {
                if(i%2 == 0)
                    cout << 1 << " ";
                else
                    cout << ans << " ";
            }
            cout << endl;
            continue;
        }

        if(ans == 1)
        {
            cout << 1 << endl;
            for(i = 0; i < n; i++)
                cout << 1 << " ";
            cout << endl;
            continue;
        }

        int flag = 0;
        for(i = 0; i < n; i++)
        {
            if(flag == 0 && i != 0 && t[i] == t[i-1])
            {
                flag = 1;
                c[i] = c[i-1];
                continue;
            }
            if(i == 0)
                c[i] = 1;
            else
                c[i] = c[i-1]%2+1;
        }

        if(flag == 0 && t[n-1] != t[0])
            ans = c[n-1] = 3;
        else if(flag == 0)
            c[n-1] = c[0];

        cout << ans << endl;
        for(i = 0; i < n; i++)
            cout << c[i] << " ";
        cout << endl;
    }
}
