#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        n >>= 1;
        cout << 8*n*(n+1)*(2*n + 1)/6 << endl;
    }
}
