#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, m, i, a[110];
    map<int, int> freq;
    cin >> T;
    while(T--)
    {
        freq.clear();
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        for(i = 1; i < 2048; i = i << 1)
            freq[i<<1] += (freq[i] >> 1);

        if(freq[2048])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
