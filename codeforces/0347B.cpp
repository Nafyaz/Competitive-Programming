#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, ans = 0;
    cin >> n;
    int a[n];

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == i)
            ans++;
    }

    if(ans == n)
    {
        cout << ans;
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] != i &&   a[a[i]] == i)
        {
            cout << ans+2;
            return 0;
        }
    }

    cout << ans + 1;
}
