#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, mx, a;
    map<int, int> freq;;
    cin >> t;
    while(t--)
    {
        freq.clear();
        mx = -1;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            freq[a]++;
            mx = max(mx, freq[a]);
        }

        cout << max(min(mx, (int)freq.size()-1), min(mx-1, (int)freq.size())) << endl;
    }
}
