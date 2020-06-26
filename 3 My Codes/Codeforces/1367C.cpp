#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i, cnt, ans;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> s;

        ans = 0;
        cnt = k;
        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
                cnt++;
            else
                cnt = 0;
            if(cnt == 2*k + 1)
            {
                cnt = k;
                ans++;
            }
        }

        if(s[n-1] == '0' && cnt > k)
            ans ++;

        cout << ans << endl;
    }
}
