#include<bits/stdc++.h>
using namespace std;

bool taken[27];
string ans;
int n, k;

void call()
{
    if(!k)
        return;
    if(ans.size() == n)
    {
        cout << ans << "\n";
        k--;
        return;
    }

    int i;
    for(i = 0; i < n; i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1;
            ans = ans + (char)('A' + i);

            call();

            taken[i] = 0;
            ans.pop_back();
        }
    }
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int t, caseno = 0;
    cin >> t;
    while(t--)
    {
        memset(taken, 0, sizeof taken);
        ans = "";
        cin >> n >> k;
        cout << "Case " << ++caseno << ":\n";
        call();
    }
}
