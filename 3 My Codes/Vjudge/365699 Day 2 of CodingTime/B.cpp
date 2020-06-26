#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, a;
    cin >> n >> m;

    vector<int> freq(m+1);

    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
    }

    int ans = 0;
    for(i = 1; i <= m; i++)
    {
        for(j = i+1; j <= m; j++)
            ans += freq[i]*freq[j];
    }

    cout << ans;
}
