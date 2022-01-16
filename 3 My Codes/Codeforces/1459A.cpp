#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, i, n, cnt;
    string r, b;

    cin >> T;

    while(T--)
    {
        cin >> n >> r >> b;

        cnt = 0;
        for(i = 0; i < n; i++)
        {
            if(r[i] > b[i])
                cnt++;
            else if(r[i] < b[i])
                cnt--;
        }

        if(cnt > 0)
            cout << "RED\n";
        else if(cnt == 0)
            cout << "EQUAL\n";
        else
            cout << "BLUE\n";
    }
}
