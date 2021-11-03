#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, ans;

    cin >> n;

    ans = 0;
    vector<int> v;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        if(a > 0 && a%2 == 0)
            ans += a;
        if(a&1)
            v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<int>());

    ans += v[0];

    for(i = 1; i+1 < v.size(); i += 2)
    {
        if(v[i] + v[i+1] > 0)
            ans += v[i] + v[i+1];
        else
            break;
    }

    cout << ans;
}
