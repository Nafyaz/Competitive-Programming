#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i, j, a[n];
    int x[n];

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
        x[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] <= a[i])
                x[i] = max(x[i], x[j] + 1);
        }
    }

    int ans = 0;
    for(i = 0; i < n; i++)
        ans = max(ans, x[i]);

    cout << ans;
}
