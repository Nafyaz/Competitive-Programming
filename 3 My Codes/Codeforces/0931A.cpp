#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, mid;
    cin >> a >> b;

    mid = (a + b)/2;
    a = abs(a - mid);
    b = abs(b - mid);

    cout << a*(a+1)/2 + b*(b+1)/2;
}
