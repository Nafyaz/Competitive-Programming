#include<bits/stdc++.h>
using namespace std;

int bigmod(int b, int p, int m)
{
    if(p == 0)
        return 1;

    int ret = bigmod(b, p/2, m);
    ret = (ret*ret)%m;

    if(p&1)
        ret = (ret*b)%m;

    return ret;
}

int babyStepGiantStep(int a, int b, int p)
{
    int i, j, c, sq = sqrt(p);
    map<int, int> babyTable;

    for(j = 0, c = 1; j <= sq; j++, c = (c*a)%p)
        babyTable[c] = j;

    int giant = bigmod(a, sq*(p-2), p);

    for(i = 0, c = 1; i <= sq; i++, c = (c*giant)%p)
    {
        if(babyTable.find((c*b)%p) != babyTable.end())
            return i*sq+babyTable[(c*b)%p];
    }

    return -1;
}

int main()
{
    int a, b, p;

    cin >> a >> b >> p;

    cout << babyStepGiantStep(a, b, p);
}
