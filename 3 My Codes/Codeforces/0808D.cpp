#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, sum1, sum2;
    map<ll, ll> freq1, freq2;

    cin >> n;

    sum1 = sum2 = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sum2 += a[i];

        freq2[a[i]]++;
    }


    for(i = 0; i < n; i++)
    {
//        cout << "sum1: " << sum1 << "; sum2: " << sum2 << "\n";
//        for(auto u : freq2)
//            cout << u.first << " " << u.second << "; " ;
//        cout << "\n\n";

        sum1 += a[i];
        sum2 -= a[i];

        freq1[a[i]]++;
        freq2[a[i]]--;

        if(sum1 == sum2)
        {
            cout << "YES";
            return 0;
        }
        else if(sum1 > sum2 && (sum1-sum2)%2 == 0 && freq1[(sum1 - sum2)/2])
        {
            cout << "YES";
            return 0;
        }
        else if(sum1 < sum2 && (sum2-sum1)%2 == 0 && freq2[(sum2 - sum1)/2])
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}

