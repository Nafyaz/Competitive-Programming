#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, l, r, len;
    vector<ll> oneIdx;
    string s;

    cin >> n >> k >> s;

    oneIdx.push_back(-1);
    for(i = 0; i < n; i++)
    {
        if(s[i] == '1')
            oneIdx.push_back(i);
    }
    oneIdx.push_back(n);

    for(i = k; i+1 < oneIdx.size(); i++)
    {
        l = oneIdx[i-k] + 1;
        r = oneIdx[i+1] - 1;

        len =
    }
}
