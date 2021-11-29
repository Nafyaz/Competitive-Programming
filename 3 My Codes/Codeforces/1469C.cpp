#include<bits/stdc++.h>
using namespace std;

int n, k;
int l, r;

bool is_valid(int h)
{
    if(h+k-1 + k <= l || h >= r+k)
        return 0;

    l = max(h, l-(k-1));
    r = min(r+k-1, h+k-1);
    return 1;
}

int main()
{
    int T, i, h, flag;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        flag = 1;

        cin >> h;
        l = r = h;

        for(i = 1; i < n; i++)
        {
            cin >> h;

            if(flag && !is_valid(h))
                flag = 0;

//            cout << flag << " " << l << " " << r << "\n";
        }

        if(flag && l == h)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
