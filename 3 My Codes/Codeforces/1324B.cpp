#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, n, a[5009], flag;

    cin >> t;
    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        flag = 0;
        vector<int> v[5009];

        for(i = 0; i < n; i++)
        {
            v[a[i]].push_back(i);
            if(v[a[i]].size() >= 3)
            {
                flag = 1;
                break;
            }
        }

        if(!flag)
        {
              for(i = 1; i <= n; i++)
              {
                  if(v[i].size() == 2 && v[i][0] < v[i][1] -1)
                  {
                      flag = 1;
                      break;
                  }
              }
        }

        cout << (flag? "YES" : "NO") << endl;
    }
}
