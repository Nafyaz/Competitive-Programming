#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nb, ns, i, b[10009], s[10009], caseno = 0;
    while(1)
    {
        cin >> nb >> ns;
        if(!nb && !ns)
            break;

        for(i = 0; i < nb; i++)
            cin >> b[i];
        for(i = 0; i < ns; i++)
            cin >> s[i];

        cout << "Case " << ++caseno << ": " << max(0, nb - ns);
        if(nb > ns)
        {
            sort(b, b+nb);
            cout << " " << b[0] << endl;
        }
        else
            cout << endl;
    }
}
/*
4 4
26
25
2
21
35
25
23
24
1 2
20
30
40
4 2
5
5
10
15
20
18
0 0
*/
