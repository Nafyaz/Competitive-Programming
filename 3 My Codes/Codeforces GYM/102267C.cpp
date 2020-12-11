#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, x, ans = 0;
    cin >> s >> x;

    while(s)
    {
        s /= x;
        ans++;
    }

    cout << ans;
}
