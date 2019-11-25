#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x, ans = 1;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 1)
            ans = -1;
    }

    cout << ans;
}
