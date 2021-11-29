#include<bits/stdc++.h>
using namespace std;

string s;

int cost(int st, int ed, char c)
{
    if(st == ed)
        return (s[st] != c);

    int mid = (st + ed)/2;
    int ret1 = 0, ret2 = 0;

    for(int i = st; i <= mid; i++)
        ret1 += (s[i] != c);
    ret1 += cost(mid+1, ed, c+1);

    for(int i = mid+1; i <= ed; i++)
        ret2 += (s[i] != c);
    ret2 += cost(st, mid, c+1);

    return min(ret1, ret2);
}

int main()
{
    int T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        cout << cost(0, n-1, 'a') << "\n";
    }
}
