#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long long l, r, x, ans;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        ans = 0;
        for(int i = log2(l); i <= log2(r) + 1; i++)
        {
            x = (1LL << i);
            if(x >= l && x <= r)
                ans += x;
        }
        cout << ans << endl;
    }

//    int news, prev = 0;
//    for(int i = 1; i < 1000; i++)
//    {
//        news = 0;
//        for(int j = 1; j <= i; j++)
//            news += i%j;
//
//        if(news == prev)
//            cout << i << endl;
//        prev = news;
//    }
}

