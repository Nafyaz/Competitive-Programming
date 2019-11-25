#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, a, prev;
    vector <int> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if(i == 0)
        {
            prev = a;
            v.push_back(a);
            continue;
        }
        if(__gcd(prev, a) != 1)
            v.push_back(1);
        v.push_back(a);
        prev = a;
    }
    int len = v.size();
    printf("%d\n", len - n);
    for(i = 0; i < len; i++)
        printf("%d ", v[i]);
}
