#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a[20], b[20];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    int ans = 0;

    for(i = 0; i < n; i++)
        ans += max(0, a[i] - b[i]);

    cout << ans;
}
