#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, s, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        if(s <= n)
            ans = s;
        else
            ans = 2*n-s;

        cout << ans << "\n";
    }
}
