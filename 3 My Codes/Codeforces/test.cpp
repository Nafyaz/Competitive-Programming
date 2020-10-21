#include<bits/stdc++.h>
using namespace std;

bool toss()
{
    return rand()%2;
}

long long cnt()
{
    long long i = 0;
    while(1)
    {
        i++;
        if(toss())
            break;
    }
    return i;
}

int main()
{
    srand (time(NULL));

    long long n = 78, sum = 0, x, mx = 0;

    for(long long i = 0; i < n; i++)
    {
        x = cnt();
        mx = max(x, mx);
        cout << x << "\n";
        sum = sum + (1LL << x);
    }

    cout << mx << "\n";
    cout << fixed;
    cout << setprecision(6) << (double)sum / n;
}
