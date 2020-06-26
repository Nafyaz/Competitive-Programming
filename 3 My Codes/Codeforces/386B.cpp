#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, T, mxsize = 0;

    deque <int> d;
    cin >> n;
    int t[n];

    for(i = 0; i < n; i++)
        cin >> t[i];
    cin >> T;

    sort(t, t + n);

    for(i = 0; i < n; i++)
    {
        while(!d.empty() && d.front() + T < t[i])
            d.pop_front();
        d.push_back(t[i]);

        mxsize = max(mxsize, (int)d.size());
    }

    cout << mxsize;
}
