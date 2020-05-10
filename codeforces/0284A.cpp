#include<bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int mod)
{
    if(b == 0)
        return 1;
    int res = bigmod(a, b>>1, mod);
    res = (res*res)%mod;
    if(b&1)
        return (a*res)%mod;
    return res;
}

int main()
{
    int i, j, p;
    cin >> p;

    if(p == 2 || p == 3)
    {
        cout << 1;
        return 0;
    }
//    if(p == 3)
//    {
//        cout << 1;
//        return 0;
//    }

    vector<int> div;
    for(i = 2; i*i < p-1; i++)
    {
        if((p-1)%i == 0)
        {
            div.push_back(i);
            div.push_back((p-1)/i);
        }
    }
    if(i*i == p-1)
        div.push_back(i);

    int flag, ans = 0;
    for(i = 2; i < p ; i++)
    {
        flag = 1;
        for(j = 0; j < div.size(); j++)
        {
            if(bigmod(i, div[j], p) == 1)
                flag = 0;
        }
        ans += flag;
    }

    cout << ans;
}
