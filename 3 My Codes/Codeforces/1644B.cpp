#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k, flag, i, a[51];

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            a[i] = n-i+1;

        k = n;
        do
        {
            flag = 1;
            for(i = 3; i <= n && flag; i++)
            {
                if(a[i] == a[i-1] + a[i-2])
                    flag = 0;
            }

            if(flag)
            {
                for(i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << "\n";
                k--;
            }

        }while(prev_permutation(a+1, a+n+1) && k);
    }
}
