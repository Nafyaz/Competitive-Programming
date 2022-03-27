#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a[40004], b[40004], sum, x, flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        sum = 0;
        for(i = 0; i < n; i++)
        {
            cin >> b[i];
            sum += b[i];
        }

        if(sum%(n*(n+1)/2) != 0)
        {
            cout << "NO\n";
            continue;
        }

        sum /= n*(n+1)/2;
        flag = 1;
        for(i = 0; i < n; i++)
        {
            x = sum - b[i] + b[(i-1+n)%n];

            if(x < 1 || x%n != 0)
            {
                flag = 0;
                break;
            }

            a[i] = x / n;
        }

        if(!flag)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
    }
}
