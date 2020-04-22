#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, i, n, k, x, total;
    cin >> t;
    while(t--)
    {
        cin >> n;
        total = 1;
        for(i = 1; (total + (1LL << i)) <= n; i++)
        {
            total += (1LL << i);
            if(n%total == 0)
            {
                cout << n/total << endl;
                break;
            }
        }
    }
}
