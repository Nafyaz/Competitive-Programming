#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if(n == 0)
    {
        cout << 10 << "\n";
        return;
    }

    else if(n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    int i, cnt[10] = {0};

    for(i = 9; i >= 2; i--)
    {
        while(n%i == 0)
        {
            n /= i;
            cnt[i]++;
        }
    }

    if(n > 1)
    {
        cout << -1 << "\n";
        return;
    }

    for(i = 2; i <= 9; i++)
    {
        while(cnt[i])
        {
            cout << i;
            cnt[i]--;
        }
    }

    cout << "\n";
}

int main()
{
    int i, n;
    cin >> n;

//    for(i = 0; i < 1000; i++)
//    {
//        cout << i << " ";
//        solve(i);
//    }

    solve(n);
}
