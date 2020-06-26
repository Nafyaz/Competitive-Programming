#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    map <string, string> mp;
    int n, i, temp;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        temp = 0;
        for(auto x : mp)
        {
            if(x.second == a)
            {
                temp = 1;
                mp[x.first] = b;
            }
        }
        if(temp == 0)
            mp[a] = b;
    }
    cout << mp.size() << endl;
    for(auto x : mp)
        cout << x.first << " " << x.second << endl;
}
