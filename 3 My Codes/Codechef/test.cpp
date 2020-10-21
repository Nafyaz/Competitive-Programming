#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    cout << ((-1) >> 1);
}
T(n)     =  2 * (T(1) + T(2) + … + T(n-3) + T(n-2) + T(n-1))
T(n-1) =  2 * (T(1) + T(2) + … + T(n-3) + T(n-2))
T(n-2) =  2 * (T(1) + T(2) + … + T(n-3))
     .
     .
     .
T(2)     =  2 * (T(1))
T(1)     =  1

Again,
T(n)     =  2 * (T(1) + T(2) + … + T(n-3) + T(n-2)) + 2 * T(n-1)
                =  T(n-1) + 2 * T(n-1)
                =  3 * T(n-1)
                =  32 * T(n-2)
                =  33 * T(n-3)
