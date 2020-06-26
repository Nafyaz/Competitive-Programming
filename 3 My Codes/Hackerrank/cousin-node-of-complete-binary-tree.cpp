#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, BT[4009], pos[4009], node;
    cin >> n;

    memset(BT, -1, sizeof BT);
    memset(pos, -1, sizeof pos);

    for(i = 1; i <= n; i++)
    {
        cin >> BT[i];
        pos[BT[i]] = i;
    }

    cin >> node;
    if(pos[node]/4 == 0)
    {
        cout << "No Cousin Available";
        return 0;
    }

    int parent = BT[pos[node]/2];
    int grandfather = BT[pos[parent]/2];
    int uncle = (BT[pos[grandfather]*2] == parent? BT[pos[grandfather]*2 + 1] : BT[pos[grandfather]*2]);

    int cousin;
    if(pos[parent] > pos[uncle] && pos[uncle]*2 + 1 <= n)
        cousin =  BT[pos[uncle]*2 + 1];
    else if(pos[parent] < pos[uncle] && pos[uncle]*2 <= n)
        cousin = BT[pos[uncle]*2];
    else
    {
        cout << "No Cousin Available";
        return 0;
    }

    cout << cousin;

}
