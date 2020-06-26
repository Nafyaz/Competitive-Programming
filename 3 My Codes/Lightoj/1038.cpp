#include<bits/stdc++.h>
using namespace std;

int x[100009];
double e[100009];


double func(int n)
{
    if(e[n] != -1)
        return e[n];

    int i, nod = 0;

    e[n] = 0;
    for(i = 1; i <= sqrt(n); i++)
    {
        if(i == 1)
        {
            nod += 2;
        }
        else if(i*i == n)
        {
            e[n] += func(i);
            nod++;
        }
        else if(n%i == 0)
        {
            nod += 2;
            e[n] += func(i) + func(n/i);
        }
    }

    e[n] = (1 + e[n]/nod) * nod /(nod - 1);

    return e[n];
}

int main()
{
    int i, n, t, caseno = 0;
    cin >> t;

    for(i = 0; i < 100009; i++)
        e[i] = -1;

    e[1] = 0;

    while(t--)
    {
        cin >> n;
        cout.precision(6);
        cout << "Case " << ++caseno << ": " << fixed << func(n) << endl;
    }
}
