#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, j, p, x, a[20009], b[20009];
    cin >> n;
    for(i = 0; i < n; i++)
        a[i] = i+1;
    for(i = n-1; i >= 0; i--)
        b[i] = n-i;


    for(i = 0; i < n; i++)
    {
        cin >> p;
        a[p-1] += i;
        for(j = p-1; j < n; j++)
        {
            a[j] += n;
            b[j] -= n;
        }
    }

    x = 1 - b[n-1];
    for(i = 0; i < n; i++)
    {
        a[i] += x;
        b[i] += x;
    }

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for(i = 0; i < n; i++)
        cout << b[i] << " ";
}
