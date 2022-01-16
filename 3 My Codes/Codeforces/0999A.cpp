#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i, st, ed;
    int a[102];

    cin >> n >> k;

    st = ed = -1;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] > k && st == -1)
            st = i;
    }
    for(i = n-1; i >= 0; i--)
    {
        if(a[i] > k)
        {
            ed = i;
            break;
        }
    }

    if(st != -1 && ed != -1)
        cout << n - ed+st-1;
    else
        cout << n;
}
