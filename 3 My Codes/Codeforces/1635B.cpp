#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, i, m;

    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        m = 0;
        for(i = 2; i+2 < n; i++)
        {
            if(a[i-2] < a[i-1] && a[i-1] > a[i] && a[i] < a[i+1] && a[i+1] > a[i+2])
            {
                m++;
                a[i] = max(a[i-1], a[i+1]);
            }
        }

        for(i = 1; i+1 < n; i++)
        {
            if(a[i-1] < a[i] && a[i] > a[i+1])
            {
                m++;
                a[i] = max(a[i-1], a[i+1]);
            }
        }

        cout << m << "\n";
        for(i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}
