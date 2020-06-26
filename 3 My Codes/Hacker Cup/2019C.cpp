#include<bits/stdc++.h>
using namespace std;
#define N 1000000

bool flag[N];
vector <int> primes;
int total;

void sieve()
{
    int i, j, val = sqrt(N) + 1;

    for(i = 4; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i += 2)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += i)
                flag[j] = 1;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
    }


}

bool is_prime(int n)
{
    if(n <= N)
        return !flag[n];

    int val = sqrt(n) + 1;
    for(int i = 0; primes[i] < val; i++)
    {
        if(n%primes[i] == 0)
            return 0;
    }

    return 1;
}

int my_nod(int n)
{
    int i, val, two = 0, p, odd = 1;

    for(i = 2; n%i == 0; n = n >> 1)
        two++;

    val = sqrt(n);
    for(i = 1; primes[i] < val; i++)
    {
        p = 0;
        while(n%primes[i] == 0)
        {
            n /= primes[i];
            p++;
        }
        odd *= (p+1);
    }

    if(n)
        odd*2;

    int even = (two + 1) * odd - odd;

    return abs(even - odd);

}

int main()
{
    sieve();

    total = primes.size();
    int l, r, T, caseno = 0, ans;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d %d", &l, &r);

        ans = 0;
        for(; l <= r; l++)
        {
            if(l&1)
            {
                if(is_prime(l))
                    ans++;
            }
            else if(my_nod(l) <= 2)
                ans++;
        }

        printf("Case #%d: %d\n", ++caseno, ans);
    }
}
