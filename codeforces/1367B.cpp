#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, a, z, e, w;
    cin >> t;
    while(t--)
    {
        cin >> n;
        w = z = e = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            if(a&1)
                e++;
            else
                z++;
            if((a&1) != (i&1))
                w++;
        }

        if(n%2 == 0 && e != z || n%2 == 1 && e != z-1)
            cout << -1 << endl;
        else
            cout << w/2 << endl;
    }
}
