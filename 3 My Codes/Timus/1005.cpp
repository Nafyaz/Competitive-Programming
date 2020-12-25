#include<bits/stdc++.h>
using namespace std;

int n, m, w[20];

int call(int i, int sum)
{
    if(i == n)
        return sum;

    int ret = call(i+1, sum);

    if(sum + w[i] <= m)
        ret = max(ret, call(i+1, sum+w[i]));

    return ret;
}

int main()
{
    int i, total = 0, x;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> w[i];
        total += w[i];
    }

    m = total/2;

    x = call(0, 0);

    cout << total - 2*x;
}
