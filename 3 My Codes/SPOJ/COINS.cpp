#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100009];

ll call(ll n)
{
    if(n == 0)
        return 0;
    if(n >= 100009)
        return call(n/2) + call(n/3) + call(n/4);

    if(dp[n] != 0)
        return dp[n];

    ll x = call(n/2) + call(n/3) + call(n/4);

    return dp[n] = max(x, n);
}

int main()
{
    ll n;

////    for(ll i = 0; i < 100; i++)
//        cout << setw(3) << i << setw(5) << call(i) << "\n";

    while(cin >> n)
        cout << call(n) << "\n";

//    cout << call(100000);
}
