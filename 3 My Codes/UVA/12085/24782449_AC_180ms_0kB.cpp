#include<bits/stdc++.h>
using namespace std;
#define ll long long

void print(ll st, ll ed)
{
    cout << '0' << st;
    if(st != ed)
        cout << '-';
    stack<int> stk;
    while(st != ed)
    {
        stk.push(ed%10);
        st /= 10;
        ed /= 10;
    }

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
}
int main()
{
//    freopen("out.txt", "w", stdout);

    ll t, caseno = 0, n, i, num, prev, st, ed, last;
    while(1)
    {
        cin >> n;
        if(!n)
            break;
        cout << "Case " << ++caseno << ":" << endl;
        last = -1;
        for(i = 0; i < n; i++)
        {
            cin >> num;
            if(i == 0)
            {
                st = num;
                ed = num;
                prev = num;
                continue;
            }

            if(num > prev + 1)
            {
                last = i;
                print(st, ed);
                st = num;
                ed = num;
                prev = num;
            }
            else
            {
                ed = num;
                prev = num;
            }

        }

//        if (last != n-1)
        print(st, ed);
        cout << endl;
    }
}
