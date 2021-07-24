#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

queue<pair<int, int>> enter, out;

void func()
{
    while(!enter.empty())
    {
        int Gl = enter.front().ff;
        int Bl = enter.front().ss;
        enter.pop();

        if(Gl > Bl)
            out.push({Gl-Bl, 0});
        else if(Gl < Bl)
            out.push({0, Bl-Gl});
    }
}

int main()
{
    int N, B, SG, SB, i, x, Gl, Bl;

    cin >> N;

    while(N--)
    {
        cin >> B >> SG >> SB;

        priority_queue<int> Green, Blue;

        for(i = 0; i < SG; i++)
        {
            cin >> x;
            Green.push(x);
        }

        for(i = 0; i < SB; i++)
        {
            cin >> x;
            Blue.push(x);
        }

        while(!Green.empty() && !Blue.empty())
        {
            for(i = 0; i < B && !Green.empty() && !Blue.empty(); i++)
            {
                enter.push({Green.top(), Blue.top()});

                Green.pop();
                Blue.pop();
            }

            func();

            while(!out.empty())
            {
                Gl = out.front().ff;
                Bl = out.front().ss;
                out.pop();

                if(Gl)
                    Green.push(Gl);
                else
                    Blue.push(Bl);
            }
        }

        if(Green.empty() && Blue.empty())
            cout << "green and blue died\n";
        else if(Blue.empty())
        {
            cout << "green wins\n";
            while(!Green.empty())
            {
                cout << Green.top() << "\n";
                Green.pop();
            }
        }
        else
        {
            cout << "blue wins\n";
            while(!Blue.empty())
            {
                cout << Blue.top() << "\n";
                Blue.pop();
            }
        }

        if(N)
            cout << "\n";
    }
}
