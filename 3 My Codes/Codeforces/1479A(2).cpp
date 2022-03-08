//Follow pranto1209
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r, mid, a, b;

    cin >> n;

    l = 1;
    r = n;

    while(l < r)
    {
        mid = (l+r)/2;

        cout << "? " << mid << "\n";
        cin >> a;
        cout << "? " << mid+1 << "\n";
        cin >> b;

        if(a > b)
            l = mid+1;
        else
            r = mid;
    }

    cout << "! " << l << "\n";
}
