#include<bits/stdc++.h>
using namespace std;

int PHI(int n)
{
    int i, cnt, ret = n;
    for(i = 2; i * i <= n; i++)
    {
        for(cnt = 0; n % i == 0; cnt++)
            n /= i;
        if(cnt)
            ret = ret / i * (i - 1);
    }

    if(n > 1)
        ret = ret / n * (n - 1);
    return ret;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << PHI(n) << endl;
    }
}
