#include<bits/stdc++.h>
using namespace std;

int lazy[400010];

void update(int node, int s, int e, int l, int r)
{
    if(s > r || e < l)
        return;
    if(s >= l && e <= r)
    {
//        lazy[2*node + 1]++;
//        lazy[2*node + 2]++;
        lazy[node]++;
        return;
    }

    int mid = (s+e)/2;
    update(2*node + 1, s, mid, l, r);
    update(2*node + 2, mid+1, e, l, r);
}

int query(int node, int s, int e, int i)
{
    if(s == e)
        return lazy[node];
    int mid = (s+e)/2;
    if(i <= mid)
        return (lazy[node] + query(2*node + 1, s, mid, i));
    else
        return (lazy[node] + query(2*node + 2, mid+1, e, i));
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int T, q, caseno = 0, l, r, i, length;
    char s[100010], c;
    scanf("%d", &T);
    while(T--)
    {
        memset(lazy, 0, sizeof(lazy));
        scanf("%s", s);
//        printf("%s\n", s);
        length = strlen(s);
        printf("Case %d:\n", ++caseno);
        scanf("%d", &q);
        while(q--)
        {
            scanf(" %c", &c);
//            printf("%c\n", c);
            if(c == 'I')
            {
                scanf("%d %d", &l, &r);
                update(0, 0, length - 1, l-1, r-1);
            }

            else
            {
                scanf("%d", &i);
                int change = query(0, 0, length - 1, i-1);
                printf("%d\n", (s[i-1]-'0'+change)%2);
            }
//            for(i = 0; i < 20; i++)
//                printf("%d ", lazy[i]);
//            printf("\n");
        }
    }
}
