#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int i, j, a[n] = {3, 4, -1, 0, 6, 2, 3};
    int x[n];

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
