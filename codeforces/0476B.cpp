#include<bits/stdc++.h>
using namespace std;
int nCr(int n, int r)
{
    if(r > n)
        return 0;
    if(r == 0)
        return 1;
    if(r == 1)
        return n;
    if(r > n/2)
        return nCr(n, n - r);

    return nCr(n-1, r-1) + nCr(n-1, r);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int i, s1sum = 0, s2sum = 0, x, y, m, q = 0, len = s1.size();

    for(i = 0; i < len; i++)
    {
        if(s1[i] == '+')
            s1sum ++;
        else
            s1sum --;

        if(s2[i] == '+')
            s2sum ++;
        else if(s2[i] == '-')
            s2sum --;
        else
            q++;
    }
    m = s1sum - s2sum;
    x = (q + m)/2;
    y = (q - m)/2;

    printf("%lf", (double)nCr(q, x) / (1 << q));
}
