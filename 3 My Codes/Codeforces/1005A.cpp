#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, prev;
    vector<int> v;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(i > 0 && a == 1)
            v.push_back(prev);

        prev = a;
    }
    v.push_back(a);

    cout << v.size() << "\n";
    for(auto u : v)
        cout << u << " ";
}
