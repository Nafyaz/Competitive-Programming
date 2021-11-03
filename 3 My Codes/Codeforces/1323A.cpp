#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, a[102], evenidx;

    cin >> t;

    while(t--)
    {
        cin >> n;

        evenidx = -1;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] % 2 == 0)
                evenidx = i;
        }

        if(n == 1 && a[0]%2 == 1)
        {
            cout << "-1\n";
            continue;
        }

        if(evenidx != -1)
        {
            cout << 1 << "\n" << evenidx +1 << "\n";
            continue;
        }

        cout << "2\n1 2\n";
    }
}
