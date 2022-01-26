#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, a[11], sum, possible;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    while(1)
    {
        possible = 1;
        sum = 0;

        for(i = 0; i < n; i++)
        {
            sum += a[i];
            if(sum > 99999999 || sum < 0)
            {
                possible = 0;
                break;
            }
        }

        if(possible)
        {
            for(i = 0; i < n; i++)
                cout << a[i] << "\n";
            return 0;
        }

        if(!next_permutation(a, a+n))
            break;
    }

    cout << "Error";
}

