#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, a[109], n, i;
    cin >> t;

    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n, greater<int>());

        for(i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
