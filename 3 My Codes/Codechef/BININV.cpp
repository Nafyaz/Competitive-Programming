#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct myStr
{
    string s;
    ll zeros;
};

myStr x[100005];

bool cmp(myStr a, myStr b)
{
    if(a.zeros != b.zeros)
        return a.zeros > b.zeros;
    return a.s < b.s;
}

int main()
{
    ll T, n, m, i, j, total_zeros, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        total_zeros = 0;
        for(i = 0; i < n; i++)
        {
            cin >> x[i].s;
//            cout << x[i].s << "\n";

            x[i].zeros = count(x[i].s.begin(), x[i].s.end(), '0');

            total_zeros += x[i].zeros;
        }

        sort(x, x+n, cmp);

        ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(x[i].s[j] == '1')
                    ans += total_zeros;
                else
                    total_zeros--;
            }
        }

        cout << ans << "\n";
    }
}
