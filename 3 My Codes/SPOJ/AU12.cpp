#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    int i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(1)
        {
            n++;
            if(is_prime(n))
                break;
        }

        cout << n << "\n";
    }
}
