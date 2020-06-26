#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    int i;
    for(i = 2; i * i <= n; i ++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int inv(int n)
{
    int ret = 0;
    while(n)
    {
        ret = ret * 10 + n%10;
        n /= 10;
    }
    return ret;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(!is_prime(n))
            cout << n << " is not prime.\n";
        else if(n == inv(n) || !is_prime(inv(n)))
            cout << n << " is prime.\n";
        else
            cout << n << " is emirp.\n";
    }
}
