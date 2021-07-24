#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, x, ans, st;

    cin >> t;

    while(t--)
    {
        cin >> n;

        map<int, int> pos;
        ans = st = 0;

        for(i = 0; i < n; i++)
        {
            cin >> x;

            if(pos.find(x) == pos.end() || pos[x] < st)
            {
                pos[x] = i;
                ans = max(ans, i - st + 1);
            }
            else
            {
                st = pos[x] + 1;
                pos[x] = i;
            }
        }

        cout << ans << "\n";
    }
}
