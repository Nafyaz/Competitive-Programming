#include<bits/stdc++.h>
using namespace std;

int bigmod(int n, int k, int mod)
{
    if(k == 0)
        return 1;

    int ret = bigmod(n, k/2, mod);

    ret = (ret * ret) % mod;

    if(k%2)
        ret = (ret * n) % mod;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        double x = log10(n)*k;
        cout << (int)pow(10, x-(int)x + 2);
        cout << "...";
        cout << setw(3) << setfill('0') << bigmod(n%1000, k, 1000) << "\n";
    }
}
