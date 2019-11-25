#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int t, i, len1, len2, ans;
    char s1[110], s2[110], *p1, *p2;
    scanf("%d", &t);
    while(t--)
    {
        ans = 1;
        scanf("%s %s", s1, s2);
        p1 = strlwr(s1);
        p2 = strlwr(s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        if(len1 != len2)
                ans = 0;
        else{
        FORAB(i, 0, len1)
        {
            if (  !(p1[i] == p2[i] || (p1[i] == 'e' && p2[i] == 'i') || (p1[i] == 'i' && p2[i] == 'e') || (p1[i] == 'b' && p2[i] == 'p')  || (p1[i] == 'p' && p2[i] == 'b') ) )
                ans = 0;

        }}
        ans? printf("Yes\n") : printf("No\n");
    }
}
