#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a[1009], i, j, sum, cnt;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        sum = 0;
        for(i = 1; i < n; i++)
        {
            cnt = 0;
            for(j = 0; j < i; j++)
            {
                if(a[j] <= a[i])
                   cnt++;
            }

            sum += cnt;
        }

        cout << sum << "\n";
    }
}
