#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k, i, j;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        if((n+1)/2 < k)
        {
            cout << "-1\n";
            continue;
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j && i%2 == 0 && k > 0)
                {
                    cout << 'R';
                    k--;
                }
                else
                    cout << '.';
            }

            cout << "\n";
        }
    }
}
