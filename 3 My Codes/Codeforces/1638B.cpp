#include<bits/stdc++.h>
using namespace std;
int a[100005];
int parityMax[2][100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        flag = 1;
        parityMax[0][0] = parityMax[1][0] = -1;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];

            parityMax[a[i]&1][i] = max(parityMax[a[i]&1][i-1], a[i]);
            parityMax[(a[i]&1)^1][i] = parityMax[(a[i]&1)^1][i-1];

            if(parityMax[a[i]&1][i-1] > a[i])
                flag = 0;
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
