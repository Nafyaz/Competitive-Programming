#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000007

ll sod[N];
ll reverseSod[N];

void allSOD()
{
    ll i, j;

    for(i = 1; i < N; i++)
    {
        for(j = i; j < N; j += i)
            sod[j] += i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    allSOD();

    ll i, t, c;

    memset(reverseSod, -1, sizeof reverseSod);
    for(i = 1; i < N; i++)
    {
        if(sod[i] < N && reverseSod[sod[i]] == -1)
            reverseSod[sod[i]] = i;
    }

    cin >> t;

    while(t--)
    {
        cin >> c;
        cout << reverseSod[c] << "\n";
    }
}
