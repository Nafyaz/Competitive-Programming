#include<bits/stdc++.h>
using namespace std;
bool absolute(int a, int b)
{
    if(abs(a) > abs(b))
        return 1;
    else
        return 0;
}
int main()
{
    int n, k, i, sum = 0;
    scanf("%d %d", &n, &k);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n, absolute);

    for(i = 0; i < n; i++)
    {
        if(a[i] < 0 && k)
        {
            a[i] *= -1;
            k--;
        }
        sum += a[i];
    }
    if(k && k%2)
        sum -= 2*a[n-1];

    printf("%d", sum);
}
