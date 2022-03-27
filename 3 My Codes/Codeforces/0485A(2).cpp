//Follow ecnerwala
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, m;

    cin >> a >> m;

    while(m%2 == 0)
        m /= 2;

    cout << (a%m == 0? "Yes" : "No");
}
