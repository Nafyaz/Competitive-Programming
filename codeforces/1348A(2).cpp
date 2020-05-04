#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (1 << ((n>>1) + 1)) - 2 << endl;
    }
}
