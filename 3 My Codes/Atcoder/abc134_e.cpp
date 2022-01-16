#include<bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> LNIS;

int main()
{
    int n, i, pos;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        if(LNIS.empty() || a[i] <= LNIS.back())
        {
            LNIS.push_back(a[i]);
            continue;
        }

        pos = upper_bound(LNIS.begin(), LNIS.end(), a[i], greater<int>()) - LNIS.begin();

        LNIS[pos] = a[i];
    }

    cout << LNIS.size();
}
