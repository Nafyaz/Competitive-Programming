#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, c, sum, ans;
    cin >> n;

    while(n--)
    {
        cin >> c >> sum;
        ans = (sum/c) * (sum/c) * c;
        ans += (sum%c) * ((sum/c + 1) * (sum/c + 1) - (sum/c) * (sum/c));

        cout << ans << endl;
    }
}
