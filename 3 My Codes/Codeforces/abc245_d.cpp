#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[202], b[202], c[202];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j, sum;

    cin >> n >> m;

    for(i = 0; i <= n; i++)
        cin >> a[i];
    for(i = 0; i <= n+m; i++)
        cin >> c[i];

    for(i = n+m; i >= n; i--)
    {
        sum = 0;
//        cout << i << ": ";
        for(j = n-1; j >= 0; j--)
        {
            if(j <= n && i-j <= m)
            {
                sum = sum + a[j]*b[i-j];
//                cout << j << " " << i-j << "; ";
            }
//            cout << "\n";
        }

        b[i-n] = (c[i] - sum)/a[n];
    }

    for(i = 0; i <= m; i++)
        cout << b[i] << " ";
}
