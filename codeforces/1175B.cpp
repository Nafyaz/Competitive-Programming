#include<bits/stdc++.h>
using namespace std;

void show(stack <int> x)
{
    while(!x.empty())
    {
        printf("%d ", x.top());
        x.pop();
    }
    printf("\n");
}

int main()
{
    int l, flag = 0;
    string a;
    stack <int> s;
    long long n, m, m2 = (1LL << 32);

    scanf("%d", &l);

    s.push(0);

    while(l--)
    {
        show(s);
        cin >> a;
        if(a == "add")
        {
            m = s.top() + 1;
            s.pop();
            s.push(m);
            if(m >= m2)
            {
                printf("OVERFLOW!!!");
                flag = 1;
                break;
            }
        }
        else if(a == "for")
        {
            scanf("%d", &m);
            s.push(m);
            s.push(0);
        }
        else
        {
            m = s.top();
            s.pop();
            m = m*s.top();
            s.pop();
            m = m + s.top();
            s.pop();
            s.push(m);
            if(m >= m2)
            {
                printf("OVERFLOW!!!");
                flag = 1;
                break;
            }
        }
    }

    if(!flag)
        printf("%d", s.top());
}
