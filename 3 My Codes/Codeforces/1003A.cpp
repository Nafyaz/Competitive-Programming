#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, freq[102] = {0}, ans = 0, a;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;

        ans = max(ans, freq[a]);
    }

    cout << ans;
}
