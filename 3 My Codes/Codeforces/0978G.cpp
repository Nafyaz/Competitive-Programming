#include<bits/stdc++.h>
using namespace std;

struct exam
{
    int s, d, c, exam_no;
};

bool cmp(exam x, exam y)
{
    return x.d < y.d;
}

int main()
{
    exam a[1003];

    int ans[1003] = {0}, flag;
    int n, m, i, j;

    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a[i].s >> a[i].d >> a[i].c;
        a[i].exam_no = i+1;

        ans[a[i].d] = m+1;
    }

    sort(a, a+m, cmp);

    flag = 1;
    for(i = 0; i < m; i++)
    {
        for(j = a[i].s; a[i].c; j++)
        {
            if(ans[j])
                continue;
            ans[j] = a[i].exam_no;
            a[i].c--;
        }

        if(j > a[i].d)
        {
            flag = 0;
            break;
        }
    }

    if(!flag)
        cout << -1;
    else
    {
        for(i = 1; i <= n; i++)
            cout << ans[i] << " ";
    }
}
