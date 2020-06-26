#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int main()
{
    int t, n, i, a, b, amax, bmin;
    cin >> t;
    while(t--)
    {
        cin >> n;
        amax = -1;
        bmin = INT_MAX;
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            amax = max(a, amax);
            bmin = min(b, bmin);
        }

        cout << max(amax - bmin, 0) << endl;
    }
}
