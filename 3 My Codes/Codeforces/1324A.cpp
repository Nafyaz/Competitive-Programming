#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, a[200], parity[2];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        parity[0] = parity[1] = 0;

        for(i = 0; i < n; i++)
        {
            parity[a[i]&1]++;
        }

        if(parity[0] && parity[1])
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
