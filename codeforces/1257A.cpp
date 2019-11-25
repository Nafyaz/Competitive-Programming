#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, x, a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> a >> b;
        cout << min(abs(a-b) + x, n-1) << endl;
    }
}
