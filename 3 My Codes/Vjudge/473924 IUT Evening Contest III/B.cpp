#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, k;

    cin >> a >> b >> k;

    cout << a/b << ".";
    a %= b;

    while(k > 1)
    {
        a *= 10;
        cout << a/b;
        a %= b;
        k--;
    }

//    cout << "\n" << a << "\n";

    if((10*((10*a)%b))/b >= 5)
        cout << (10*a)/b + 1;
    else
        cout << (10*a)/b;
}
