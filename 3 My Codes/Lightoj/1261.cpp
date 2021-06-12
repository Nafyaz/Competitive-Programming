#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, caseno = 0, i, j, n, m, k, p;
    int want[39][39], picked[39], x, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> k;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < k; j++)
                cin >> want[i][j];
        }

        cin >> p;

        memset(picked, 0, sizeof picked);
        for(i = 0; i < p; i++)
        {
            cin >> x;
            picked[x] = 1;
        }

        for(i = 0; i < n; i++)
        {
            ans = 0;
            for(j = 0; j < k; j++)
            {
                x = want[i][j];
                if(x > 0 && picked[x])
                {
                    ans = 1;
                    break;
                }

                if(x < 0 && !picked[-x])
                {
                    ans = 1;
                    break;
                }
            }

            if(!ans)
                break;
        }

        cout << "Case " << ++caseno << ": " << (ans? "Yes\n" : "No\n");
    }
}
