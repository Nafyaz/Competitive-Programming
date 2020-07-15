#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, k;
    cin >> n >> k;

    ll temp = n, c2 = 0, c5 = 0;
    while(temp % 2 == 0)
    {
        c2++;
        temp >>= 1;
    }
    while(temp % 5 == 0)
    {
        c5++;
        temp /= 5;
    }

    while(c2 < k)
    {
        n <<= 1;
        c2++;
    }
    while(c5 < k)
    {
        n *= 5;
        c5++;
    }

    cout << n;
}
