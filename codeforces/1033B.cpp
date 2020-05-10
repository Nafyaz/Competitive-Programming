#include<bits/stdc++.h>
using namespace std;

long long is_prime(long long n)
{
    if(n == 2)
        return 1;
    else if(n%2 == 0)
        return 0;
    long long i;
    for(i = 3; i*i <= n; i += 2)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    long long t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a-b == 1 && is_prime(a+b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
