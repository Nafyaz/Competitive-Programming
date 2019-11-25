#include<bits/stdc++.h>
using namespace std;

int n, x[101];
double e[101];

double func(int i)
{
    int j;
    if(e[i] != -1)
        return e[i];

    e[i] = x[i];

    double r = 0;
    for(j = 1; j <= 6; j++)
    {
        if(i + j > n)
            break;
        r += func(i+j);
    }

    if(j > 1)
        e[i] += r/(j - 1);
    return e[i];
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, t, caseno = 0;
    cin >> t;
    while(t--)
    {
        for(i = 0; i < 101; i++)
            e[i] = -1;

        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> x[i];


        cout.precision(6);
        cout << "Case " << ++caseno << ": " << fixed << func(1) << endl;
    }
}
