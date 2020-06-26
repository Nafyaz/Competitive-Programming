#include<bits/stdc++.h>
using namespace std;

int ans[3009];

int func(int n)
{
    int fact = 0;
    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
        {
            fact++;
            if(fact > 2)
                return 0;
            while(n%i == 0)
                n /= i;
        }
    }

    if(n > 1)
        fact++;

    return fact == 2;
}

int main()
{
    int i, j, n;

    for(i = 6; i < 3009; i++)
    {
        ans[i] = ans[i-1] + func(i);
    }

    cin >> n;
    cout << ans[n];
}
