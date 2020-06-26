#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a[100009], l[100009], r[100009], mx = 0;
    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    for(i = 1; i <= n; i++)
    {
        if(i == 1 || a[i] <= a[i-1])
            l[i] = 1;
        else
            l[i] = l[i-1]+1;
        mx = max(mx, l[i]);
    }


    for(i = n; i >= 1; i--)
    {
        if(i == n || a[i] >= a[i+1])
            r[i] = 1;
        else
            r[i] = r[i+1] +1;
        mx = max(mx, r[i]);
    }

    for(i = 1; i <= n; i++)
    {
        if(i < n)
            mx = max(mx, l[i]+1);
        if(i > 1)
            mx = max(mx, r[i]+1);
        if(i > 1 && i < n && a[i+1] - a[i-1] > 1)
            mx = max(mx, l[i-1]+r[i+1]+1);
    }

    cout << mx;

}
