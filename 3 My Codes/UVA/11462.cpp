#include<bits/stdc++.h>
using namespace std;

int a[2000009];

int main()
{
    int t = 0, n, i;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        for(i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);

        for(i = 0; i < n; i++)
            cout << a[i] << (i != n-1? " " : "");

        cout << "\n";
    }
}

