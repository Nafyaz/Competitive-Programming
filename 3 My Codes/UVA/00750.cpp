#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, r, c;

    cin >> t;

    while(t--)
    {
        cin >> r >> c;

        r--;
        c--;

        solve(r, c);
    }
}
