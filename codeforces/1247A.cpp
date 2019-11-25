#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;

    if(a == 9 && b == 1)
        cout << 9 << " " << 10;
    else if(b - a >= 2 || a > b)
        cout << -1;
    else if(a + 1 == b)
        cout << a << " " << b;
    else
        cout << a*10 << " " << b*10 + 1;
}
