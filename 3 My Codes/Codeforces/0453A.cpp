#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double m, k, ans = 0;

    cin >> m >> n;

    for(k = 1; k <= m; k++)
        ans += k*(pow(k/m, n) - pow((k-1)/m, n));

    cout << ans;
}
