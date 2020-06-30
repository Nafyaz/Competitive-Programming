#include<bits/stdc++.h>
using namespace std;
#define N 1000009

int divcnt[N], ans[11][N];
bool flag[N];
vector<int> primes;

void linsieve()
{
    int i, j;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes.push_back(i);
        for(j = 0; j < primes.size() && i * primes[j] < N; j++)
        {
            flag[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}

void func()
{
    int i, j;

    for(auto p : primes)
    {
        for(i = 1; i * p < N; i++)
            divcnt[i * p]++;
    }

    for(i = 1; i < N; i++)
    {
        for(j = 0; j <= 10; j++)
            ans[j][i] = ans[j][i-1] + (divcnt[i] == j);
    }
}

int main()
{
    linsieve();
    func();

    int t, a, b, n;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> n;
        cout << ans[n][b] - ans[n][a-1] << endl;
    }
}
