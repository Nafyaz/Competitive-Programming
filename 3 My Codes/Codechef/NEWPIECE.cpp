#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, a, b, p, q;

    cin >> T;

    while(T--)
    {
        cin >> a >> b >> p >> q;

        if(a == p && b == q)
            cout << 0 << "\n";
        else if((a+b)%2 == (p+q)%2)
            cout << 2 << "\n";
        else
            cout << 1 << "\n";
    }
}
