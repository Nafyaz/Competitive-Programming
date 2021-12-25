#include<bits/stdc++.h>
using namespace std;

int main()
{
    int freq[1003] = {0}, i, n, a[51];

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]] ++;
    }

    vector<int> v;
    for(i = 0; i < n; i++)
    {
        freq[a[i]] --;

        if(freq[a[i]] == 0)
            v.push_back(a[i]);
    }

    cout << v.size() << "\n";
    for(auto u : v)
        cout << u << " ";
}
