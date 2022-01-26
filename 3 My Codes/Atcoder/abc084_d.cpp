#include<bits/stdc++.h>
using namespace std;

bool flag[100005];
vector<int> primes;
int pre[100005];

void sieve()
{
    int i, j;

    flag[2] = 1;
    for(i = 3; i < 100005; i += 2)
        flag[i] = 1;

    for(i = 3; i*i < 100005; i += 2)
    {
        if(flag[i])
        {
            for(j = i*i; j < 100005; j += 2*i)
                flag[j] = 0;
        }
    }

    primes.push_back(2);
    for(i = 3; i < 100005; i += 2)
    {
        if(flag[i])
            primes.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int q, l, r, i;

    for(i = 1; i < 100005; i++)
    {
        pre[i] = pre[i-1];
        if(i%2 == 1 && flag[i] && flag[(i+1)/2])
            pre[i]++;
    }

    cin >> q;
    while(q--)
    {
        cin >> l >> r;

        cout << pre[r] - pre[l-1] << "\n";
    }
}
