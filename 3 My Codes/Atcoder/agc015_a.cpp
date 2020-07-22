#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;

    if(a > b || (n == 1 && a != b))
    {
        cout << 0;
        return 0;
    }

    cout << (n - 2)*(b-a) + 1;

}
