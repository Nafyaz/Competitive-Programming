#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, m, i, a[40];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; (1 << i) <= n; i++)
        {
            a[i] = (1 << i);
            n -= (1 << i);
        }

        m = i;

        if(n)
        {
            a[i] = n;
            m++;
        }

        sort(a, a+m);

        cout << m-1 << endl;
        for(i = 1; i < m; i++)
            cout << a[i] - a[i-1] << " ";
        cout << endl;
    }
}
