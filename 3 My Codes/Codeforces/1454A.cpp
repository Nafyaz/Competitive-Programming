#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, i;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cout << (i)%n + 1 << " ";

        cout << "\n";
    }
}
