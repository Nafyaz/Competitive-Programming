#include<bits/stdc++.h>
using namespace std;

int dims[1000], n, mcm[1000][1000];

int main()
{
    int i, j, k;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> dims[i];

    for (i = 1; i <= n; i++)
		mcm[i][i] = 0;


    int len, cost;
	for (len = 2; len <= n; len++)
	{
		for (i = 1; i + len - 1 < n; i++)
		{
			j = i + len - 1;
			mcm[i][j] = INT_MAX;

			for (k = i; j < n && k <= j - 1; k++)
			{
				cost = mcm[i][k] + mcm[k+1][j] + dims[i-1]*dims[k]*dims[j];
                mcm[i][j] = min(mcm[i][j], cost);
			}
		}
	}

	cout << mcm[1][n-1];
}
