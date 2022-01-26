#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i;

    cin >> n;

    for(i = sqrt(n); i >= 1; i--)
    {
        if(n%i == 0)
        {
            cout << int(log10(n/i) + 1);
            break;
        }
    }
}
