#include<bits/stdc++.h>
using namespace std;

bool taken[35];
string s, ans;
int r, len;
void call(int start)
{
    int i;
    if(ans.size() == r)
    {
        cout << ans << endl;
        return;
    }

    for(i = start; i < len; i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1;
            ans = ans + s[i];

            call(i+1);

            taken[i] = 0;
            ans.pop_back();
        }
        while(s[i] == s[i+1])
            i++;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    while(cin >> s >> r)
    {
        memset(taken, 0, sizeof(taken));
        len = s.size();
        sort(s.begin(), s.end());
        call(0);
    }
}
