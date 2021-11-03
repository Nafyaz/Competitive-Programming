#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, prev, temp, ans = 1;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(i == 0 || a <= prev)
            temp = 1;
        else
            ans = max(ans, ++temp);

        prev = a;
    }

    cout << ans;
}
