#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, n, l, caseno = 0, pl[15], total, cap, flag;
    cin >> t;
    while(t--)
    {
        cin >> n >> l;
        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> pl[i];
            total += pl[i];
        }

        flag = (total <= l);

        for(i = 0; i < n; i++)
        {
            cin >> cap;
            flag &= (cap >= pl[i]);
        }

        cout << "Case " << ++caseno << ": " << (flag? "Yes\n" : "No\n");
    }
}
/*
3
3  5
1  2  3
1  3  3
3  6
1  2  3
1  3  2
3  6
1  2  3
3  3  3
*/
