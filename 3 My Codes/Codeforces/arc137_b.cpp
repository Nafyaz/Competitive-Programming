#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a, consecutive[2] = {0}, mx[2] = {0}, curr;

    cin >> n;

    curr = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        if(a != curr)
        {
            curr = a;
            consecutive[curr] = 1;
        }
        else
            consecutive[curr]++;

        mx[curr] = max(mx[curr], consecutive[curr]);

        cout << curr << "; " << consecutive[0] << " " << consecutive[1] << "\n";
    }

    cout << mx[0] + mx[1] + 1;
}
