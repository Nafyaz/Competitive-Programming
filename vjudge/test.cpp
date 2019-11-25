#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, c, m, x, team, l, r, mid;
    cin >> T;
    while(T--)
    {
        cin >> c >> m >> x;

        r = min(c, m);
        l = 0;
        while(l <= r)
        {
            mid = (l+r)/2;
            cout << l << " " << r << " " << mid << endl;
            if(c+m+x-2*mid == mid)
                break;
            else if(c+m+x -2*mid < mid)
                r = mid-1;
            else
                l = mid+1;
        }

        cout << mid << endl;
    }
}
