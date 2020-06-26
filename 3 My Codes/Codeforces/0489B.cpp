#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
    cin >> n;
    int b[n];

    for(i = 0; i < n; i++)
        cin >> b[i];
    cin >> m;
    int g[m];
    for(j = 0; j < m; j++)
        cin >> g[j];

    sort(b, b+n);
    sort(g, g+m);

    int ans = 0;

    i = 0; j = 0;

    while(i < n && j < m)
    {
        if(abs(b[i] - g[j]) <= 1)
        {
            i++;
            j++;
            ans++;
        }
        else if(b[i] - g[j] > 1)
            j++;
        else if(g[j] - b[i] > 1)
            i++;
    }

    cout << ans;
}
