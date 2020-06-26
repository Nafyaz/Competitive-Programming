#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int pr[N];
int find(int r){
   return (pr[r]==r) ? r : pr[r]=find(pr[r]);
}

int main()
{
    int n = 10;
    for(int i = 1;i <= n;i++)pr[i] = i;

    while(1)
    {
        int a,b;
        cin >> a >> b;///Connect a and b

        int u = find(a);
        int v = find(b);
        pr[v] = u;


        for(int i = 1;i <= n;i++)cout << find(i) << " ";
        cout << endl;
    }

}
