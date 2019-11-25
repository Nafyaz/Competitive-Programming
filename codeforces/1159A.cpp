#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, start = 0, now = 0;
    string a;
    cin >> n >> a;

    for(i = 0; i < n; i++)
    {
        if(a[i] == '-')
            now--;
        else
            now++;
        if(now < 0)
        {
            start = min(start, now);
        }
    }
    printf("%d", now - start);
}
