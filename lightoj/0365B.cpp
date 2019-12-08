#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int a[n], x, mx = 0;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i > 1 && a[i] == a[i-1] + a[i-2])
            x++;
        else
            x = 0;
        mx = max(mx, x);
    }

    cout << min(n, mx + 2);
}
