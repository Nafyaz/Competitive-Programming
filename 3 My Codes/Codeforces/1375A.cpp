#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            cout << (i&1? abs(a) : -abs(a)) << " ";
        }
        cout << endl;
    }
}
