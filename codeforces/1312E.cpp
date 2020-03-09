#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, cnt = 509;

    cin >> n;

    vector<int> a(n), b;

    for(i = 0; i < n; i++)
        cin >> a[i];

    while(cnt--)
    {
        for(i = 0; i < a.size(); i++)
        {
            if(i && a[i] == a[i-1])
            {
                b.back()++;
                i++;
            }
            else
                b.push_back(a[i]);
        }

        for(auto u : b)
            cout << u << " ";
        cout << endl;
        a = b;
        b.clear();
    }

    cout << a.size();
}
