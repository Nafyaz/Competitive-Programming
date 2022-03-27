#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, sum;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if((n&(n-1)) == 0)
            cout << "-1\n";
        else
        {
            for(k = 2; k*(k-1)/2 <= n; k++)
            {
                sum = k * (k-1) / 2;
                if((n-sum)%k == 0 && n-sum >= k)
                    break;
            }

            cout << k << "\n";
        }
    }
}
