#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, s, h, m, flag = 0;
    cin >> n >> s;
    int v[n];

    for(i = 0; i < n; i++)
    {
        cin >> h >> m;
        v[i] = h*60 + m;
        if(!flag)
        {
            if(i == 0 && v[i] > s)
            {
                flag = 1;
                cout << "0 0\n";
            }
            else if(v[i-1] + s + 1 < v[i] - s)
            {
                flag = 1;
                cout << (v[i-1] + s + 1)/60 << " " << (v[i-1] + s + 1)%60 << endl;
            }
            else if(i == n-1)
            {
                cout << (v[i] + s + 1)/60 << " " << (v[i] + s + 1)%60;
            }
        }
    }
}
