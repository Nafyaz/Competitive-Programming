#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, x;
    vector<int> num;
    valid[10];
    while(cin >> n >> m)
    {
        for(i = 0; i < 10; i++)
            valid[i] = 1;
        for(i = 0; i < m; i++)
        {
            cin >> x;
            valid[x] = 0;
        }
        num.clear();
        for(i = 0; i < m; i++)
        {
            if(valid[i])
                num.push_back(i);
        }
    }
}
