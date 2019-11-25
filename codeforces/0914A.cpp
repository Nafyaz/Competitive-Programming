#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x;

    cin >> n;
    int a[n];

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, greater<int>());

    for(i = 0; i < n; i++)
    {
        if(a[i] < 0)
        {
            cout << a[i];
            break;
        }

        x = sqrt(a[i]);
        if(x*x != a[i])
        {
            cout << a[i];
            break;
        }
    }
}
