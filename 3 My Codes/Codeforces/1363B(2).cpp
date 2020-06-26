#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, totalone, totalzero, ones[1009], zeros[1009], ans;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        totalzero = zeros[0] = totalone = ones[0] = 0;
        for(i = 0; i < s.size(); i++)
        {
            totalone += (s[i] == '1');
            ones[i+1] = ones[i] + (s[i] == '1');

            totalzero += (s[i] == '0');
            zeros[i+1] = zeros[i] + (s[i] == '0');
        }

        n = s.size();
        ans = INT_MAX;
        for(i = 0; i <= n; i++)
        {
            ans = min(ans, zeros[i] + totalone - ones[i]);
            ans = min(ans, ones[i] + totalzero - zeros[i]);
        }

        cout << ans << endl;
    }
}

