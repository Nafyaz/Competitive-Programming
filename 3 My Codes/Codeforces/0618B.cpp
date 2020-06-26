//Thanks to Editorial
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, x, mx, flag = 0;
    cin >> n;
    int a[n+1];

    for(i = 1; i <= n; i++)
        a[i] = n;

    for(i = 1; i <= n; i++)
    {
        mx = 0;
        for(j = 1; j <= n; j++)
        {
            cin >> x;
            mx = max(x, mx);
        }

        a[i] = mx;

        if(!flag && a[i] == n-1)
        {
            flag = 1;
            a[i] = n;
        }
    }

    for(i = 1; i <= n; i++)
        cout << a[i] << " ";
}
