#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, sz = 0;
    deque<int> d;
    deque<int>::iterator it;

    while(cin >> x)
    {
        it = lower_bound(d.begin(), d.end(), x);
        d.insert(it, x);

        sz++;

        if(sz & 1)
            cout << d[sz/2] << "\n";
        else
            cout << (d[sz/2-1] + d[sz/2])/2 << "\n";
    }
}
