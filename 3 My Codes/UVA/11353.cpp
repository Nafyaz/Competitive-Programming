#include<bits/stdc++.h>
using namespace std;
#define N 2000009
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



int func(int n)
{
    int i, c, ret = 0;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(c = 0; n%primes[i] == 0; c++)
            n /= primes[i];

        ret += c;
    }

    if(n > 1)
        ret++;
    return ret;
}

int main()
{
    linsieve();


    int i, n, t = 0;

    vector<pair<int, int> > v;
    for(i = 1; i <= 2000000; i++)
        v.push_back({func(i), i});

//    for(i = 0; i < 10; i++)
//    cout << v[i].first << " " << v[i].second << endl;

    sort(v.begin(), v.end());

    while(1)
    {
        cin >> n;
        if(!n)
            break;
        cout << "Case " << ++t << ": " << v[n-1].second << endl;
    }
}
