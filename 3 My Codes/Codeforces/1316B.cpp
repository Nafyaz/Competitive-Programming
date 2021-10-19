#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, ansk;
    string s, s2, s3;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        string ans(n, 'z');
        ansk = INT_MAX;

        for(k = 1; k <= n; k++)
        {
            s2 = s.substr(0, k-1);
            s3 = s.substr(k-1);

            if((n-k+1)%2 == 1)
                reverse(s2.begin(), s2.end());

            if(ans > s3+s2 || ansk > n)
            {
                ans = s3+s2;
                ansk = k;
            }
        }

        cout << ans << "\n" << ansk << "\n";
    }
}
