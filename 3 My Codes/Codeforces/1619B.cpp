#include<bits/stdc++.h>
using namespace std;

vector<int> num;
set<int> s;

int main()
{
    int t, n, i;

    for(i = 1; i*i <= 1000000009; i++)
        s.insert(i*i);
    for(i = 2; i*i*i <= 1000000009; i++)
        s.insert(i*i*i);

    for(auto u : s)
        num.push_back(u);

    cin >> t;

    while(t--)
    {
        cin >> n;

        cout << (upper_bound(num.begin(), num.end(), n) - num.begin()) << "\n";
    }
}
