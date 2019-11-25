#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    long long int n, k, i;
    scanf("%I64d %I64d", &n, &k);

    long long int a[k], minl = n, mini = -1;
    FORAB(i, 0, k)
    {
        scanf("%I64d", &a[i]);
        if(n%a[i] < minl)
        {
            minl = n%a[i];
            mini = i;
        }
    }
    mini == -1? printf("1 0") : printf("%I64d %I64d", mini + 1, n/a[mini]);
}
