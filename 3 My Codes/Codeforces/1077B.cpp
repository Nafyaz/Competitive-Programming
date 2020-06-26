#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n, i, a[110];
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for(i = 0; i < n - i - 4; i++)
    {
        if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 && a[i+3] == 0 && a[i+4] == 1)
        {
            a[i+2] = 0;
            ans++;
        }
    }

    for(i = 0; i < n - 2; i++)
    {
        if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 1)
        {
            a[i+2] = 0;
            ans++;
        }
    }

    cout << ans;
}
