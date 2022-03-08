#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, k, l, r, mid, ones, zeros;

    cin >> n >> t >> k;

    l = 1;
    r = n;

    while(l < r)
    {
        mid = (l+r)/2;

        cout << "? " << l << " " << mid << "\n";
        cin >> ones;

        zeros = mid-l+1 - ones;
        if(zeros < k)
        {
            k -= zeros;
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }

    cout << "! " << l << "\n";
}
