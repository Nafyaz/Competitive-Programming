#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, ans = 0;
    cin >> n;

    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    for(i = 0; i < n; i++)
    {
        if(a[i] == -1)
            continue;
        for(j = i+1; j < n; j++)
        {
            if(a[j] != -1 && a[j] % a[i] == 0)
                a[j] = -1;
        }

        ans++;
    }

    cout << ans;
}
