#include<bits/stdc++.h>
using namespace std;

int n;
deque<int> ans;
bool taken[20];

bool is_prime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

void print(deque<int> dq)
{
    for(int i = 0; i < dq.size(); i++)
    {
        cout << dq[i];
        if(i + 1 != dq.size())
            cout << " ";
    }
    cout << "\n";
}

void call()
{
    int i;

    if(ans.size() == n && is_prime(ans.back() + 1))
    {
        print(ans);
        return;
    }

    for(i = 2; i <= n; i++)
    {
        if(taken[i] == 0 && is_prime(ans.back() + i))
        {
            taken[i] = 1;
            ans.push_back(i);

            call();

            taken[i] = 0;
            ans.pop_back();
        }
    }
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int caseno = 0;
    while(cin >> n)
    {
        memset(taken, 0, sizeof taken);
        ans.clear();
        ans.push_back(1);
        taken[1] = 1;

        if(caseno != 0)
            cout << "\n";
        cout << "Case " << ++caseno << ":\n";
        call();
    }
}
