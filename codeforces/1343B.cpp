#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n%4 != 0)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(i = 0; i < n/2; i++)
            cout << 2*i + 2 << " ";
        for(i = 0; i < n/2 -1; i++)
            cout << 2*i + 1 << " ";
        cout << 2*i + 1 + n/2 << endl;
    }
}
