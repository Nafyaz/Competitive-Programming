#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, p, K, ans;

    cin >> T;

    while(T--)
    {
        cin >> N >> p >> K;

        ans = (p%K) * (N/K);
        ans += min(N%K, p%K);
        ans += p/K + 1;

        cout << ans << "\n";
    }
}
