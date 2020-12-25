#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, caseno = 0, a[10009], i, x, pos;

    while(1)
    {
        cin >> n >> q;
        if(!n && !q)
            break;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        cout << "CASE# " << ++caseno << ":\n";
        while(q--)
        {
            cin >> x;

            pos = lower_bound(a, a+n, x) - a;

            if(a[pos] != x)
                cout << x << " not found\n";
            else
                cout << x << " found at " << pos + 1 << "\n";
        }
    }
}
