#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define N 10000007

int a[1000006];
pair<int, int> divisorOf[N];

int leastFactor[N];
bool flag[N];
vector<int> primes;

vector<int> factors[10000006];

void linSieve2()
{
    int i, j;

    for(i = 2; i < N; i++)
    {
        if(leastFactor[i] == 0)
        {
            primes.push_back(i);
            leastFactor[i] = i;
        }

        for(j = 0; j < (int)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < N; j++)
            leastFactor[i * primes[j]] = primes[j];
    }
}

void putFactor(int i)
{
    int n = a[i], x = a[i];


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    linearSieve();

    int i, n;

    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];

    }
}
