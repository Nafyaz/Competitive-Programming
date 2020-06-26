#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, total, ones[1009], ans;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        total = ones[0] = 0;
        for(i = 0; i < s.size(); i++)
        {
            total += (s[i] == '1');
            ones[i+1] = ones[i] + (s[i] == '1');
        }

        n = s.size();
        ans = INT_MAX;
        for(i = 0; i <= n; i++)
        {
            ans = min(ans, (i - ones[i]) + total - ones[i]);
//            cout << ans << " ";
            ans = min(ans, ones[i] + ((n-i) - (total - ones[i])));
//            cout << ans << endl;
        }

        cout << ans << endl;
    }
}
