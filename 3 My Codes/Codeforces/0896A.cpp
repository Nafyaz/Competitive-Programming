#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100005];
string s1 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s2[3] = {"What are you doing while sending \"", "\"? Are you busy? Will you send \"", "\"?"};

char func(ll n, ll k)
{
    if(n == 0)
    {
        if(k <= s1.size())
            return s1[k-1];
        else
            return '.';
    }

    if(k <= s2[0].size())
        return s2[0][k-1];

    k-= s2[0].size();

    if(f[n] == -1 || k <= f[n-1])
        return func(n-1, k);

    k -= f[n-1];
    if(k <= s2[1].size())
        return s2[1][k - 1];

    k -= s2[1].size();
    if(k <= f[n-1])
        return func(n-1, k);

    k-= f[n-1];
    if(k <= s2[2].size())
        return s2[2][k-1];

    return '.';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q, n, k, i;

    memset(f, -1, sizeof f);
    f[0] = s1.size();
    for(i = 1; i <= 55; i++)
        f[i] = s2[0].size() + f[i-1] + s2[1].size() + f[i-1] + s2[2].size();

    cin >> q;

    while(q--)
    {
        cin >> n >> k;

        cout << func(n, k);
    }
}
