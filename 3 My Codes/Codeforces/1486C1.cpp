#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;

int findSecondMax(int l, int r)
{
    if(mp.find({l, r}) != mp.end())
        return mp[{l, r}];

    cout << "? " << l << " " << r << "\n";
    cin >> mp[{l, r}];

    return mp[{l, r}];
}

int main()
{
    int n, l, r, mid, ans = -1;
    int xFull, xHalf;

    cin >> n;

    l = 1;
    r = n;
    while(l+1 < r)
    {
        mid = (l+r)/2;
        xFull = findSecondMax(l, r);

        if(xFull <= mid && l < mid)
        {
            xHalf = findSecondMax(l, mid);

//            if(l+1 == mid)
//                ans = l+mid-xHalf;

            if(xHalf == xFull)
                r = mid;
            else
                l = mid;
        }
        else if(xFull >= mid && mid < r)
        {
            xHalf = findSecondMax(mid, r);

//            if(mid+1 == r)
//                ans = mid+r - xHalf;

            if(xHalf == xFull)
                l = mid;
            else
                r = mid;
        }
        else
            break;
    }

//    if(ans == -1)
//    {
        xFull = findSecondMax(l, r);
        ans = l+r-xFull;
//    }

    cout << "! " << ans << "\n";
}

