#include<bits/stdc++.h>
using namespace std;

int n;
double dp[302][302][302];

double call(int c1, int c2, int c3)
{
    if(c1 < 0 || c2 < 0 || c3 < 0)
        return 0;
    if(c1 == 0 && c2 == 0 && c3 == 0)
        return 0;

//    cout << c1 << " " << c2 << " " << c3 << "\n";

    if(dp[c1][c2][c3] != 0)
        return dp[c1][c2][c3];

    int c0 = n - c1 - c2 - c3;
    double e1 = (1 + call(c1-1, c2, c3)) * c1/n;
    double e2 = (1 + call(c1+1, c2-1, c3)) * c2/n;
    double e3 = (1 + call(c1, c2+1, c3-1)) * c3/n;

    double e = ((double)c0/n + e1 + e2 + e3) * n / (n-c0);

    return dp[c1][c2][c3] = e;
}

int main()
{
    int i, a, cnt[4] = {0};

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        cnt[a]++;
    }

    cout << fixed << setprecision(10) << call(cnt[1], cnt[2], cnt[3]);
}
