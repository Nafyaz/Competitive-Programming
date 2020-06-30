#include<bits/stdc++.h>
using namespace std;

#define N 1000009

bitset<N> flag, check;
int psum[N];

void sieve()
{
    int i, j;
    flag[0] = flag[1] = 1;
    for(i = 4; i <= N; i += 2)
        flag[i] = 1;
    for(i = 3; i * i <= N; i += 2)
    {
        if(!flag[i])
        {
            for(j = i * i; j <= N; j += 2 * i)
                flag[j] = 1;
        }
    }

}

int bigmod(int a, int b)
{
    int ret = 1;
    while(b)
    {
        if(b&1)
            ret = ret * a;

        a = a * a;
        b >>= 1;
    }

    return ret;
}

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int i, T, n;
    sieve();
    queue<int> primes;
    primes.push(2), check[2] = 1;
    primes.push(3), check[3] = 1;
    primes.push(5), check[5] = 1;
    primes.push(7), check[7] = 1;

    while(!primes.empty())
    {
        int p = primes.front();
        primes.pop();
//        print(primes);
        for(i = 1; i <= 9; i++)
        {
            int q = bigmod(10, log10(p) + 1)*i + p;
            if(q < N && !flag[q])
            {
                check[q] = 1;
                primes.push(q);
            }
        }
    }

    for(i = 2; i < N; i++)
        psum[i] = psum[i-1] + (int)check[i];

    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << psum[n] << endl;
    }
}
