#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll n)
{
    ll product = 1, sum = 0;

    while(n)
    {
        product *= (n%10);
        sum += (n%10);
        n /= 10;
    }

    return (product%sum == 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, A, B, n, ans;

    cin >> T;

    while(T--)
    {
        cin >> A >> B;

        ans = 0;
        for(n = A; n <= B; n++)
        {
            if(check(n))
                ans++;
        }

        cout << "Case #" << ++caseno << ": " << ans << "\n";
    }
}
