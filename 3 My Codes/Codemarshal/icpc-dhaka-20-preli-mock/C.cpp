#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[3];

    cin >> a[0] >> a[1] >> a[2];

    sort(a, a+3);

    if(a[0] == a[2])
        cout << "Equilateral Triangle\n";
    else if(a[0] == a[1] || a[1] == a[2])
        cout << "Isosceles Triangle\n";
    else
        cout << "Bad Triangle\n";
}
