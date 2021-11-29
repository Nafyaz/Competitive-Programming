#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, a, oddCount;

    cin >> t;

    while(t--)
    {
        oddCount = 0;

        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a&1)
                oddCount++;
        }

        cout << oddCount/2 << "\n";
    }
}
