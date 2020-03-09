#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, m, n;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cout << (n%m == 0? "YES" : "NO") << endl;
    }
}
