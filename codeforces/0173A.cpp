#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, m, k, lcm, ans1 = 0, ans2 = 0;
    string a, b;

    scanf("%d", &n);

    cin >> a >> b;
    m = a.size();
    k = b.size();

    lcm = m*k/__gcd(m, k);

    string temp = a;
    for(i = 1; i < lcm/m; i++)
        a = a + temp;
    temp = b;
    for(i = 1; i < lcm/k; i++)
        b = b + temp;

    //cout << a << " " << b << endl;

    for(i = 0; i < min(lcm, n); i++)
    {
        if(a[i] == b[i])
            continue;
        if((a[i] == 'R' && b[i] == 'S') || (a[i] == 'S' && b[i] == 'P') || (a[i] == 'P' && b[i] == 'R'))
            ans2++;
        else
            ans1++;
    }
    if(lcm > n)
    {
        printf("%d %d", ans1, ans2);
        return 0;
    }

    ans1 = ans1 * (n/lcm);
    ans2 = ans2 * (n/lcm);

    n = n - (n/lcm)*lcm;
    for(i = 0; i < n; i++)
    {
        if(a[i] == b[i])
            continue;
        if((a[i] == 'R' && b[i] == 'S') || (a[i] == 'S' && b[i] == 'P') || (a[i] == 'P' && b[i] == 'R'))
            ans2++;
        else
            ans1++;
    }
    printf("%d %d", ans1, ans2);
}
