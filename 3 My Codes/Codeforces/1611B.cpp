#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T, a, b, pairs, ans;

    cin >> T;

    while(T--)
    {
        cin >> a >> b;

        if(a < b)
            swap(a, b);

        pairs = b;

        a-= b;
        b = 0;

        ans = min(pairs, a/2);
        pairs -= ans;
        ans += pairs/2;

        cout << ans << "\n";
    }
}
