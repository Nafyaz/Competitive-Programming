#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    double a,b,d;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf %lf", &a, &b, &d);
        printf("%0.8f\n", d*d/2);
    }
}
