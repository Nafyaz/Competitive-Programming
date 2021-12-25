#include<bits/stdc++.h>
using namespace std;

int b[100005];

int main()
{
    int n, i, j, k, diff, c, ans, changes, flag;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> b[i];

    if(n <= 2)
    {
        cout << 0;
        return 0;
    }

    ans = INT_MAX;
    for(i = -1; i <= 1; i++)
    {
        for(j = -1; j <= 1; j++)
        {
            diff = b[1] + j - b[0] - i;
            c = b[1] + j;

            changes = 0;
            if(i != 0)
                changes++;
            if(j != 0)
                changes++;

            flag = 1;
            for(k = 2; k < n; k++)
            {
                c = c + diff;

                if(abs(c - b[k]) > 1)
                {
                    flag = 0;
                    break;
                }

                if(c != b[k])
                    changes++;
            }

            if(flag)
                ans = min(ans, changes);
        }
    }

    if(ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}
