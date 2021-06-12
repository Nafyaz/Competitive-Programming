#include<bits/stdc++.h>
using namespace std;

int weight[100009], neighbour[100009];

int main()
{
    int N, i, j, ans;

    while(cin >> N)
    {
        for(i = 0; i < (1<<N); i++)
            cin >> weight[i];

        for(i = 0; i < (1<<N); i++)
        {
            neighbour[i] = 0;
            for(j = 0; j < N; j++)
                neighbour[i] += weight[i^(1<<j)];
        }

        ans = -1;
        for(i = 0; i < (1<<N); i++)
        {
            for(j = 0; j < N; j++)
                ans = max(ans, neighbour[i] + neighbour[i^(1<<j)]);
        }

        cout << ans << "\n";
    }
}
