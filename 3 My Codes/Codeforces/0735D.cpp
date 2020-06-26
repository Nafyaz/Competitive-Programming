#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    int i, j, val = sqrt(n) + 1;
    for(i = 2; i < val; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main ()
{
    int n, x, ans = 0;

    cin >> n;

    if(is_prime(n))
        cout << 1;
    else
    {
        if(n&1 && is_prime(n-2))
            cout << 2;
        else if(n&1)
            cout << 3;
        else
            cout << 2;
    }
}
