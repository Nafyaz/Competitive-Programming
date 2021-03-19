#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int i, n;

    for(i = 20; i >= 1 && v.size() <= 1000000; i--)
    {
        vector<int> rev = v;
        reverse(rev.begin(), rev.end());
        v.push_back(i);
        v.insert(v.end(), rev.begin(), rev.end());
    }

    cin >> n;
    for(i = 0; i < n; i++)
        cout << v[i] << " ";
}
