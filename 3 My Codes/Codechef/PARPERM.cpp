#include<bits/stdc++.h>
using namespace std;
#define N 100005

bool flag[N];
vector<int> primes;

void sieve()
{
    int i, j;

    flag[2] = 1;
    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < N; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

int main()
{
    sieve();

    int T, n, k, i, pos, combined, separated, next_separated;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        pos = upper_bound(primes.begin(), primes.end(), n/2) - primes.begin();
        separated = (upper_bound(primes.begin(), primes.end(), n) - primes.begin()) - pos;
        separated += 1;

        combined = n - separated;

        if(k <= separated)
        {
            cout << "YES\n";

            cout << 1 << " ";
            k--;

            for(; k; k--, pos++)
                cout << primes[pos] << " ";
            cout << "\n";
        }

        else if(k < combined)
            cout << "NO\n";

        else
        {
            cout << "YES\n";
            next_separated = pos;
            for(i = 2; i <= n; i++)
            {
                if(primes[next_separated] == i)
                {
                    next_separated++;
                    continue;
                }

                k--;
                cout << i << " ";
            }

            if(k)
            {
                cout << 1 << " ";
                k--;
            }
            for(; k; k--, pos++)
                cout << primes[pos] << " ";
            cout << "\n";
        }
    }
}
