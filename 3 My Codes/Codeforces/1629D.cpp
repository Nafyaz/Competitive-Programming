#include<bits/stdc++.h>
using namespace std;

string s[100005];

bool isPal(string x)
{
    if(x.size() == 1)
        return 1;
    if(x.size() == 2 && x[0] == x[1])
        return 1;
    if(x.size() == 3 && x[0] == x[2])
        return 1;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        flag = 0;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];

            if(!flag && isPal(s[i]))
                flag = 1;
        }

        if(flag)
        {
            cout << "YES\n";
            continue;
        }


    }
}
