#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 1)
        {
            cout << -1 << endl;
            continue;
        }

        for(i = 1; i < n; i++)
            cout << 7;
        cout << 8 << endl;
    }
}
