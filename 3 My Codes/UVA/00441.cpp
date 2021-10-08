#include<bits/stdc++.h>
using namespace std;

int k, s[15], a[6];

void call(int x, int y)
{
    int i;

    if(x == 6)
    {
        for(i = 0; i < 6; i++)
        {
            cout << a[i];
            if(i != 5)
                cout << " ";
        }
        cout << "\n";
        return;
    }

    if(y < k)
    {
        a[x] = s[y];
        call(x+1, y+1);
        call(x, y+1);
    }
}

int main()
{
    int i, caseno = 0;

    while(cin >> k)
    {
        if(!k)
            break;

        if(caseno)
            cout << "\n";
        caseno++;

        for(i = 0; i < k; i++)
            cin >> s[i];

        call(0, 0);

    }
}
