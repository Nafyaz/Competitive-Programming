#include<bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}

int main()
{
    int T, i, j, dmin, d;
    int x[8], y[8], z[8];

    cin >> T;

    while(T--)
    {
        for(i = 0; i < 8; i++)
            cin >> x[i] >> y[i] >> z[i];

        map<int, int> freq;
        dmin = INT_MAX;

        for(i = 0; i < 8; i++)
        {
            for(j = i+1; j < 8; j++)
            {
                d = dist(x[i], y[i], z[i], x[j], y[j], z[j]);
                dmin = min(d, dmin);
                freq[d]++;
            }
        }

        if(freq.size() != 3 || freq[dmin] != 12 || freq[2*dmin] != 12 || freq[3*dmin] != 4)
            cout << "NO\n";
        else
            cout << "YES\n";
    }


}
