//A slightly modified code of shakkhor vai.
//shakkhor vai is
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    int n, i, m = -1;
    cin >> a;
    n = a.size() - 1;
    for (i=0; i<n; i++)
    {
        if(int(a[i]) % 2 == 0)
        {
            m=i;
            if(a[n] > a[i])
                break;
        }
    }

    if (m == -1)
        cout << "-1" << endl;

    else
    {
        swap(a[n],a[m]);
        cout <<a<< endl;
    }
    return 0;
}
