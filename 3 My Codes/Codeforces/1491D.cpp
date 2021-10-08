//Too hard. editorial is shit. random public er comment deikha bujhchi.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q, u, v, i, ucnt, vcnt, flag;

    cin >> q;

    while(q--)
    {
        cin >> u >> v;

        ucnt = vcnt = 0;

        flag = 1;

        for(i = 0; i < 32; i++)
        {
            if(u > v || ucnt < vcnt)
            {
                flag = 0;
                break;
            }

            ucnt += (u&1);
            vcnt += (v&1);

            u >>= 1;
            v >>= 1;
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
