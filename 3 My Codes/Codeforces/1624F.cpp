#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, n, l, r, mid, up, new_up, v;

    cin >> n;

    l = 1;
    r = n-2;

    cout << "+ " << n-1 << endl;
    cin >> up;
    v = n-1;

    while(l <= r)
    {
        mid = (l+r)/2;

        cout << "+ " << mid << endl;
        cin >> new_up;

        if(up == new_up)
        {
            r = mid - 1;
            v = mid;
        }
        else
            l = mid + 1;
    }

    if(l == 1)
        cout << "! " << up*n << endl;
    else
        cout << "! " << up*n - v << endl;
}
