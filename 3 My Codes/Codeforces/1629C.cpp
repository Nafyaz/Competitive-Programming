#include<bits/stdc++.h>
using namespace std;

queue<int> a;
queue<int> d[200005];
queue<int> ans;

void Print(queue<int> x)
{
    while(!x.empty())
    {
        cout << x.front() << " ";
        x.pop();
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i, v, mx;

    cin >> T;

    while(T--)
    {
        cin >> n;

//        a.clear();
//        ans.clear();
//        for(i = 0; i <= n; i++)
//        {
//            while(!d[i].empty())
//                d[i].pop();
//        }

        for(i = 0; i < n; i++)
        {
            cin >> v;
            a.push(v);
            d[v].push(i);
        }

//        for(i = 0; i <= n; i++)
//        {
//            cout << i << ": ";
//            while(!d[i].empty())
//            {
//                cout << d[i].front() << " ";
//                d[i].pop();
//            }
//            cout << "\n";
//        }
//        while(!a.empty())
//        {
//            cout << a.front() << " ";
//            a.pop();
//        }

        while(!a.empty())
        {
            mx = -1;
            for(i = 0; i <= n && !d[i].empty(); i++)
            {
                mx = max(mx, d[i].front());
//                d[i].pop();
            }

//            Print(a);

            if(mx != -1)
            {
                ans.push(i);

                mx = mx - n + (int)a.size();

                while(mx >= 0)
                {
                    d[a.front()].pop();
                    a.pop();
                    mx--;
                }
            }
            else
            {
                ans.push(0);
                d[a.front()].pop();
                a.pop();
            }
        }

        cout << ans.size() << "\n";
        while(!ans.empty())
        {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << "\n";
    }
}
