/*input
0 2
1
3
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 7000005
#define ll long long
#define MOD 1000000007

int nexti[mx][2];
int node = 1;
bool get_bit(int n, int pos)
{
    return bool((1 << pos) & n);
}
int insert(int n)
{
    int tmp = 1;
    for(int i = 5; i>=0; i--)
    {
         cout << i << " " << node << endl;
        int bit = get_bit(n, i);
        if(nexti[tmp][bit] == 0)
            nexti[tmp][bit] = ++node;
        tmp = nexti[tmp][bit];
    }
}

int get_min(int n)
{
    int tmp = 1;
    int ans = 0;
    for(int i = 5; i>=0; i--)
    {
        int bit = get_bit(n, i);
        if(nexti[tmp][bit])
        {
            tmp = nexti[tmp][bit];
            ans *= 2;
        }
        else
        {
            tmp = nexti[tmp][!bit];
            ans = ans*2 + 1;
        }
    }
    return ans;
}

void show()
{
    int tmp = 1, bit = 0;

    for(int i = 5; i >= 0; i--)
    {

        if(nexti[tmp][bit])
        {
            cout << i << " " << tmp << "\n";
            tmp = nexti[tmp][bit];
        }
        else
            cout << "hah ";
    }
}

int flag[mx];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        flag[a] = 1;
    }
    for(int i = 0; i<(1<<5); i++)
        if(!flag[i]) insert(i);

//    show();

    int x = 0;
    while(m--)
    {
        int a;
        scanf("%d", &a);
        x ^= a;
        printf("%d\n", get_min(x));
    }
    return 0;
}
