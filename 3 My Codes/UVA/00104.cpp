#include<bits/stdc++.h>
using namespace std;

double mat[20][20];
double before[20], now[20];
stack<int> st;
int n;

bool call(int level)
{
    if(level == n+1)
        return -1;

    int i, j, mxidx[20];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(now[i] < before[j] * mat[j][i])
            {
                now[i] = before[j] * mat[j][i];
                mxidx[i] = j;
            }
        }
    }

    if(now[0] > 1.01)
    {
        st.push(mxidx[0]);
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        before[i] = now[i];
        now[i] = 0;
    }

    int ret = call(level + 1);

    if(ret != -1)
    {
        st.push(mxidx[ret]);
        return mxidx[ret];
    }
    else
        return ret;
}

int main()
{
    int i, j;

    while(cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j)
                    mat[i][j] = 1;
                else
                    cin >> mat[i][j];
            }
        }

        memset(before, 0, sizeof before);
        memset(now, 0, sizeof now);
        st.push(1);

        now[0] = 1;

        st.push(call(0));

        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
}
