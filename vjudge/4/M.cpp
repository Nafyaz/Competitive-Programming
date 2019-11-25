#include<bits/stdc++.h>
using namespace std;
int h, w, k;
int func(int i, int j)
{
    if(i == k-1)
        return (max(0, j-1) + 1) * max(1, (h+1) * (w-k-1));
    for(int p = j+1; p <= h; p++)
        return (max(0, j-1) + 1) * func(i+1, p) * max(1, h - p);
}
int main()
{
    scanf("%d %d %d", &h, &w, &k);
    printf("%d", func(1, 0));
}
