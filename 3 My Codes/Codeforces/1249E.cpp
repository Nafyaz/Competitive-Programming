#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c, i, a[200009], b[200009], t[2][200009];

    cin >> n >> c;

    for(i = 1; i < n; i++)
        cin >> a[i];
    for(i = 1; i < n; i++)
        cin >> b[i];

    for(i = 1; i <= n; i++)
        t[0][i] = t[1][i] = INT_MAX;

    t[0][1] = 0;
    t[1][1] = c;
    cout << "0 ";
    for(i = 2; i <= n; i++)
    {
        t[0][i] = min(t[0][i-1] + a[i-1], t[1][i-1] + a[i-1]);
        t[1][i] = min(t[0][i-1] + b[i-1] + c, t[1][i-1] + b[i-1]);

        cout << min(t[0][i], t[1][i]) << " ";
    }
}
