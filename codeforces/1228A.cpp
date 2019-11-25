#include<bits/stdc++.h>
using namespace std;

bool func(int x)
{
    int cnt[10] = {0};
    while(x)
    {
        cnt[x%10]++;

        if(cnt[x%10] > 1)
            return 0;

        x /= 10;
    }
    return 1;
}


int main()
{
    int l, r, x;
    cin >> l >> r;

    for(x = l; x <= r; x++)
    {
        if(func(x))
        {
            cout << x;
            return 0;
        }
    }

    cout << -1;
}
