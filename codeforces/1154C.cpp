#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long ans, a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    ans = min(a/3, min(b/2, c/2));

    a = a - 3*ans;
    b = b - 2*ans;
    c = c - 2*ans;

    char food[8] = "frcfcrf";
    ans = 7*ans;

    map <char, long long> mp;
    long long day, maxday = 0, start, x, y, z;
    for(start = 0; start < 7; start++)
    {
        mp['f'] = a;
        mp['r'] = b;
        mp['c'] = c;
        day = start%7;
        while(mp[food[day%7]])
        {
            //printf("%lld %lld %lld ", x, y, z);
            mp[food[day%7]] --;
            day++;
            //printf("%lld %lld %lld %lld \n", mp['f'], mp['r'], mp['c'], day);
        }
        maxday = max(maxday, day - start%7);
        //printf("%lld\n", day);
    }
    printf("%lld", ans + maxday);
}
