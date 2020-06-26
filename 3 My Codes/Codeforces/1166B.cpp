#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k, n, m, i, j, val;
    scanf("%d", &k);
    if(k < 25)
    {
        printf("-1");
        return 0;
    }

    val = sqrt(k) + 1;
    for(i = 5; i < val; i++)
    {
        if(k % i == 0)
        {
            n = i;
            m = k/i;
            break;
        }
    }
    if(i == val)
    {
        printf("-1");
        return 0;
    }
    string s;
    string x = "aeiou";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            s += x[((j % 5) + i) % 5];
    }
    cout << s;
}
