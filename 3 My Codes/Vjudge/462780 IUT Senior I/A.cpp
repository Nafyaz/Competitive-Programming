#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n, a[100005], prefix[100005];

bool is_ok(ll len)
{
    if(len == 0)
        return 1;
    if(len > n)
        return 0;

    ll i, j, doubleCnt = 0;
    map<ll, ll> freq;

    for(i = 1; i < len; i++)
    {
        freq[a[i]]++;
        if(freq[a[i]] == 2)
            doubleCnt++;
    }

    for(i = len, j = 1; i <= n; i++, j++)
    {
        freq[a[i]]++;
        if(freq[a[i]] == 2)
            doubleCnt++;

//        cout << i << "; " << doubleCnt << "\n";
//        for(auto u : freq)
//            cout << u.ff << " " << u.ss << "\n";
//        cout << "\n";

        if(!doubleCnt && prefix[i] - prefix[j-1] == len*(len+1)/2)
            return 1;

        freq[a[j]]--;
        if(freq[a[j]] == 1)
            doubleCnt--;
    }

    return 0;
}

int main()
{
    ll i, low, high, mid, ans = 1;

    cin >> n;

    prefix[0] = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }

    low = 0;
    high = n+10;

//    cout << is_ok(3);

    while(low <= high)
    {
        mid = (low + high)/2;

        if(is_ok(mid))
        {
            ans = mid + 1;
            low = mid + 1;
        }
        else
            high = mid-1;
    }

    cout << ans;
}
