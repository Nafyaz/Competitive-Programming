#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

pair<int, int> ro, kn, bi;

bool safe(int i, int j)
{
    pair<int, int> p = {i, j};
    if(p == ro || p == kn || p == bi)
        return 1;

    if(i == ro.ff)
    {
        if(i != kn.ff && i != bi.ff)
            return 0;
         if(i == kn.ff && (kn.ss < min(j, ro.ss) || kn.ss > max(j, ro.ss)))
                return 0;
         if(i == bi.ff && (bi.ss < min(j, ro.ss) || bi.ss > max(j, ro.ss)))
                return 0;
    }
    if(j == ro.ss)
    {
        if(j != kn.ss && j != bi.ss)
            return 0;
        if(j == kn.ss && (kn.ff < min(i, ro.ff) || kn.ff > max(i, ro.ff)))
            return 0;
        if(j == bi.ss && (bi.ff < min(i, ro.ff) || bi.ff > max(i, ro.ff)))
            return 0;
    }

    if(i == kn.ff + 2 && (j == kn.ss + 1 || j == kn.ss-1))
        return 0;
    if(i == kn.ff - 2 && (j == kn.ss + 1 || j == kn.ss-1))
        return 0;
    if(i == kn.ff + 1 && (j == kn.ss + 2 || j == kn.ss - 2))
        return 0;
    if(i == kn.ff - 1 && (j == kn.ss + 2 || j == kn.ss - 2))
        return 0;

    if(i - j == bi.ff - bi.ss)
    {
        if(i - j != kn.ff - kn.ss && i - j != ro.ff - ro.ss)
            return 0;
        if(i - j == kn.ff - kn.ss && (kn.ff < min(i, bi.ff) || kn.ff > max(i, bi.ff)))
            return 0;
        if(i - j == ro.ff - ro.ss && (ro.ff < min(i, bi.ff) || ro.ff > max(i, bi.ff)))
            return 0;
    }
    if(i + j == bi.ff + bi.ss)
    {
        if(i + j != kn.ff + kn.ss && i + j != ro.ff + ro.ss)
            return 0;
        if(i + j == kn.ff + kn.ss && (kn.ff < min(i, bi.ff) || kn.ff > max(i, bi.ff)))
            return 0;
        if(i + j == ro.ff + ro.ss && (ro.ff < min(i, bi.ff) || ro.ff > max(i, bi.ff)))
            return 0;
    }

    return 1;
}

int main()
{
    string x;
    int n = 3, i, j;
    while(n--)
    {
        cin >> x;
        if(x[0] == 'N')
        {
            kn.ff = x[1] - 'a';
            kn.ss = x[2] - '1';
        }
        else if(x[0] == 'R')
        {
            ro.ff = x[1] - 'a';
            ro.ss = x[2] - '1';
        }
        else if(x[0] == 'B')
        {
            bi.ff = x[1] - 'a';
            bi.ss = x[2] - '1';
        }
    }

    int ans = 0;

//    cout << safe(5, 2) << endl;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(!safe(i, j))
            {
                ans++;
//                cout << " * ";
            }
//            else
//                cout << " . ";
        }
//        cout << endl;
    }

    cout << ans;
}
