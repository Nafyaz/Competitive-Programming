#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, caseno = 0, n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if(n == 2)
            cout << "Case #" << ++caseno << ": 0\n";
        else
            cout << "Case #" << ++caseno << ": 1\n";
    }
}
