#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a[100005], i, l, r;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i]/abs(a[i]);
        }

        for(l = 0, r = 0; l < n; l++)
        {
            while(r < n-1 && a[r]*a[r+1] == -1)
                r++;

            cout << r-l+1 << " ";

            if(l == r)
                r++;
        }

        cout << "\n";
    }
}
