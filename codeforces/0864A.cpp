#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, x, freq[110] = {0};
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    int dis = 0, pos1, pos2;

    pos1 = pos2 = -1;

    for(i = 0; i < 110; i++)
    {
        if(freq[i])
        {
            dis++;
            if(pos1 == -1)
                pos1 = i;
            else
                pos2 = i;
        }
        if(dis > 2)
        {
            cout << "NO";
            return 0;
        }
    }

    if(dis == 1 || freq[pos1] != freq[pos2])
        cout << "NO";

    else
    {
        cout << "YES" << endl;
        cout << pos1 << " " << pos2;
    }
}
