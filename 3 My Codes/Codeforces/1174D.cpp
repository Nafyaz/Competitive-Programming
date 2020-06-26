#include<bits/stdc++.h>
using namespace std;
int n, x, mx;
vector <int> s, mxs;

bool check(int i, int nowx)
{
    if(nowx == 0 || nowx == x)
        return 0;
    if(i == s.size())
        return 1;

    bool a = check(i+1, nowx);
    bool b = check(i+1, nowx ^ s[i]);

    return a&b;
}
void func(int i)
{
    if(i == (1 << n))
    {
        /*for(auto u : s)
            printf("%d ", u);
        printf("\n");*/
        if(s.size() > mx)
        {
            mx = s.size();
            mxs = s;
        }
        return;
    }

    func(i+1);
    if(check(0, i))
    {
        s.push_back(i);
        func(i+1);
        s.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &x);
    func(1);

    printf("%d\n", mx);
    for(int i = 0; i < mx; i++)
        printf("%d ", mxs[i]);
}
