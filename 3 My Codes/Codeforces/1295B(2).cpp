//credit pranto1209
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, x, i, total, ans, bal, z, o;
    string s;

    cin >> T;

    while(T--)
    {
        ans = bal = 0;
        cin >> n >> x >> s;

        z = count(s.begin(), s.end(), '0');
        o = n - z;
        total = z - o;

        ans = (x == 0);

        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
                bal++;
            else
                bal--;

            if(total == 0 && bal == x)
            {
                ans = -1;
                break;
            }
            else if(total && (x - bal)%total == 0 && (x - bal)/total >= 0)
                ans++;
        }
        cout << ans << "\n";
    }
}
