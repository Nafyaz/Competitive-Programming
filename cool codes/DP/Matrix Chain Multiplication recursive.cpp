#include<bits/stdc++.h>
using namespace std;

int dims[1000], n, mcm[1000][1000];

int call(int i, int j)
{
    if(i+1 >= j)
        return 0;

    if(mcm[i][j] != 0)
        return mcm[i][j];

    int ret = INT_MAX;

    for(int k = i+1; k <= j-1; k++)
    {
        int cost = call(i, k);
        cost += dims[i]*dims[k]*dims[j];
        cost += call(k, j);

        ret = min(ret, cost);
    }

    return mcm[i][j] = ret;
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> dims[i];
    cout << call(0, n-1);
}
