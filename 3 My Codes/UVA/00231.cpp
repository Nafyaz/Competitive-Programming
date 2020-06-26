#include<bits/stdc++.h>
using namespace std;

vector <int> v;
stack <int> s;
int n, mx;

void gen(int i)
{
    if(i == n)
    {
        if(mx < s.size())
            mx = s.size();
        return;
    }
    gen(i+1);
    if(s.empty() || s.top() >= v[i])
    {
        s.push(v[i]);
        gen(i+1);
        s.pop();
    }
}

int main()
{
    int i, c = 0;

    scanf("%d", &i);
    while(i != -1)
    {
        n++;

        v.push_back(i);

        scanf("%d", &i);
        if(i == -1)
        {
            printf("Test #%d:\n  ", ++c);
            gen(0);
            cout << "maximum possible interceptions: " << mx << endl;

            mx = n = 0;
            v.clear();
            while(!s.empty())
                s.pop();

            scanf("%d", &i);
            if(i == -1)
            {
                break;
            }
            cout << endl;
        }
    }
}
