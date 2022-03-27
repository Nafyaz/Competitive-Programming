#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, caseno = 0, i, j, ans;
    string I, P;

    cin >> t;

    while(t--)
    {
        cin >> I >> P;

        i = j = 0;
        ans = -1;

        while(1)
        {
            if(i == I.size())
            {
                ans = P.size() - I.size();
                break;
            }
            else if(j == P.size())
                break;

            if(I[i] == P[j])
            {
                i++;
                j++;
                continue;
            }
            else
                j++;
        }

        if(ans == -1)
            cout << "Case #" << ++caseno << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << ++caseno << ": " << ans << "\n";
    }
}
