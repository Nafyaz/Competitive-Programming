#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if(n == 0)
    {
        cout << 10 << "\n";
        return;
    }

    else if(n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    int i, primes[4] = {2, 3, 5, 7}, cnt[10] = {0};

    for(i = 0; primes[i] <= n && i < 4; i++)
    {
        while(n%primes[i] == 0)
        {
            n /= primes[i];
            cnt[primes[i]]++;
        }
    }

    if(n > 1)
    {
        cout << -1 << "\n";
        return;
    }

    cnt[8] = cnt[2] / 3;
    cnt[2] = cnt[2] % 3;
    cnt[4] = cnt[2] / 2;
    cnt[2] = cnt[2] % 2;

    cnt[9] = cnt[3] / 2;
    cnt[3] = cnt[3] % 2;

    for(i = 2; i <= 9; i++)
    {
        while(cnt[i])
        {
            cout << i;
            cnt[i]--;
        }
    }

    cout << "\n";
}

int main()
{
    freopen("out.txt", "w", stdout);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << "alllabels[" << i << "]" << "[" << j << "]= " << "grid" << i << j << "; ";
        cout << "\n";
    }
}
