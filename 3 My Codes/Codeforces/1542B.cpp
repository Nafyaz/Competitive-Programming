#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, n, a, aPower, b, flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> a >> b;

        aPower = 1;
        map<ll, bool> powerRepeat;

        flag = 0;
        while(aPower <= n && powerRepeat.find(aPower) == powerRepeat.end())
        {
            powerRepeat[aPower] = 1;

            if(aPower%b == n%b)
            {
                flag = 1;
                break;
            }

            aPower = aPower * a;
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
