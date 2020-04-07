#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, a[209], i, p, v;
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n >> x;
        for(i = 0; i < n; i++)
        {
            cin >> p;
            a[p] = 1;
        }
        v = 1;
        while(x--)
        {
            while(a[v])
                v++;
            a[v] = 1;
        }

        while(a[v])
            v++;

        cout << (a[v]? v : v-1) << endl;
    }
}
