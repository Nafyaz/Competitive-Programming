#include<bits/stdc++.h>
using namespace std;

int isprime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int t, n, temp, cnt, i, caseno = 0;
    vector<int> primes;
    for(i = 2; i < 100; i++)
    {
        if(isprime(i))
            primes.push_back(i);
    }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << "Case " << ++caseno << ": " << n << " =";
        for(auto p : primes)
        {
            if(p > n)
                break;
            if(p != 2)
                cout << " *";
            cout << " " << p << " (";

            temp = n;
            cnt = 0;
            while(temp)
            {
                cnt += temp/p;
                temp /= p;
            }

            cout << cnt << ")";
        }
        cout << endl;
    }
}
