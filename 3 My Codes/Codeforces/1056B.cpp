#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i, j, n, m, freq[1009] = {0}, cnt;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cnt = n/m;
        if(i && i <= n%m)
            cnt++;
        freq[(i*i)%m] += cnt;
    }

    long long ans = 0;
    for(i = 0; i < m; i++)
        ans += freq[i] * freq[(m-i)%m];

    cout << ans;
}
