#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a[100009], total = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    if(total == 1)
    {
        cout << -1;
        return 0;
    }



}
