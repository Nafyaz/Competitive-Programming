#include<bits/stdc++.h>
using namespace std;

long long int a[10000000], b[10000000];
int n, k, maxpl;
vector<int>q;
void rec(int i, int pl)
{
    if(q.size() > k || i == n)
        return;
    int minb = 1000010;
    for(int j = 0; j < q.size(); j++)
    {
        if(q[j] < minb)
            minb = q[j];
    }
    printf("\n");
    if(maxpl < pl*minb)
        maxpl = pl*minb;
    printf("hi, man\n");


    rec(i+1, pl);

    q.push_back(b[i]);
    rec(i+1, pl + a[i]);
    if(q.size() != 0)
        q.pop_back();

}

int main()
{
    int i;
    scanf("%d %d", &n, &k);

    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    rec(0, 0);
    printf("%d",maxpl);
}
