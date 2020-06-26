#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, k, n, total_one, ans;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        total_one = count(s.begin(), s.end(), '1');
        ans = max(0, total_one - 1);

        for(int st = 0; st < k; st++)
        {
            int cnt1 = 0, cnt0 = 0;
            int costR, costL = 0;
            for(i = st; i < n; i += k)
            {
                cnt1 += s[i] == '1';
                cnt0 += s[i] == '0';

                costL = max(costL, -cnt1 + cnt0);
                costR = -cnt1 + cnt0;
                ans = min(ans, total_one + costR - costL);
            }
        }

        cout << ans << endl;
    }
}
