#include <bits/stdc++.h>
#define M (A, B) memset (A,b,sizeof (a))
#define N (a)-' 0 '
using namespacestd;
Char s[205];
int way[205];
BOOL vis[205];
int N;
int Lenss;
BOOL OK;
void Dfs(int Pos, int num)
{
    if(pos==Lenss)
    {
        OK=true;     /*4111109876532*/
        for(int I=1; i<=n; i++)
            printf ("%d%s", Way[i],i==n?"\ n":" ");
        return ;
    }
    if(!vis[n (S[pos])]&&n (S[pos]) <=N)
    {
        vis[n (S[pos])]=1;
        Way[num]=N (S[pos]);
        DFS (POS+1, num+1);
        Vis[n (S[pos])=0;
              if(OK)return ;
      }
    if(pos+1<lenss&&!vis[(s[pos]-'0')*Ten+ (s[pos+1]-'0')]&& (s[pos]-'0')*Ten+ (s[pos+1]-'0') <=N)
    {
        vis[(S[pos]-'0')*Ten+ (s[pos+1]-'0')]=1;
        Way[num]= (s[pos]-'0')*Ten+ (s[pos+1]-'0');
        DFS (POS+2, num+1);
        vis[(S[pos]-'0')*Ten+ (s[pos+1]-'0')]=0;
        if(OK)
            return ;
    }
}
int Main ()
{
    while(gets (s))
    {
        int lens=strlen (s);
        M (Vis,0);
        M (The,0);
        vis[0]=1;
        N=0;
        Lenss=0;
        OK=false;
        while(true)
        {
            n++;
            if(n<Ten)
                lenss++;
            Elselenss+=2;
            if(Lenss==lens)
                Break;
        }
        OK=0;
        DFS (0,1);
    }
    return 0;
}
