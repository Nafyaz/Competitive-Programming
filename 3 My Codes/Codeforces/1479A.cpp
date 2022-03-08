#include<bits/stdc++.h>
using namespace std;

int a[100005];

void Get(int i)
{
    if(a[i] != -1)
        return;

    cout << "? " << i << "\n";
    cin >> a[i];
}

int main()
{
    int n, l, r, mid, ans;

    cin >> n;

    if(n == 1)
    {
        cout << "! 1" << "\n";
        return 0;
    }

    memset(a, -1, sizeof a);
    a[0] = a[n+1] = INT_MAX;

    Get(1);
    Get(2);
    if(a[1] < a[2])
    {
        cout << "! 1" << "\n";
        return 0;
    }

    Get(n-1);
    Get(n);
    if(a[n-1] > a[n])
    {
        cout << "! " << n << "\n";
        return 0;
    }

    l = 2;
    r = n-2;
    while(l <= r)
    {
        mid = (l+r)/2;

        Get(mid);
        Get(mid+1);

        if(a[mid] > a[mid+1])
        {
            l = mid + 1;
            ans = mid + 1;
        }
        else
        {
            r = mid - 1;
            ans = mid;
        }
    }

    cout << "! " << ans << "\n";

    return 0;
}
