#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll func(ll n, ll b)
{
    ll ret = 0;
    while(n)
    {
        ret += n % b;
        n /= b;
    }

    return ret;
}

int main()
{

//    freopen("out.txt", "w", stdout);

    ll q, n, l, r, i, sum, f;

    n = 216;

    cout << setw(3) << n << "\n";

    for(i = 2; i <= 7; i++)
        cout << setw(3) << i << setw(3) << func(n, i) << "\n";

    cout << "---------\n";
}
