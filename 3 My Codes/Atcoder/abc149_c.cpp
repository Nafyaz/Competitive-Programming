#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    int i;
    for(i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int x;

    cin >> x;

    while(1)
    {
        if(isPrime(x))
        {
            cout << x;
            break;
        }

        x++;
    }
}
