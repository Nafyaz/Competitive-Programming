#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, x, y, v;
    int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    bool digToDis[10][7];

    digToDis[0][0] = 1, digToDis[0][1] = 1, digToDis[0][2] = 1, digToDis[0][3] = 1, digToDis[0][4] = 1, digToDis[0][5] = 1, digToDis[0][6] = 0;
    digToDis[1][0] = 1, digToDis[1][1] = 1, digToDis[1][2] = 0, digToDis[1][3] = 0, digToDis[1][4] = 0, digToDis[1][5] = 0, digToDis[1][6] = 0;
    digToDis[2][0] = 1, digToDis[2][1] = 0, digToDis[2][2] = 1, digToDis[2][3] = 1, digToDis[2][4] = 0, digToDis[2][5] = 1, digToDis[2][6] = 1;
    digToDis[3][0] = 1, digToDis[3][1] = 1, digToDis[3][2] = 1, digToDis[3][3] = 0, digToDis[3][4] = 0, digToDis[3][5] = 1, digToDis[3][6] = 1;
    digToDis[4][0] = 1, digToDis[4][1] = 1, digToDis[4][2] = 0, digToDis[4][3] = 0, digToDis[4][4] = 1, digToDis[4][5] = 0, digToDis[4][6] = 1;
    digToDis[5][0] = 0, digToDis[5][1] = 1, digToDis[5][2] = 2, digToDis[5][3] = 0, digToDis[5][4] = 1, digToDis[5][5] = 1, digToDis[5][6] = 1;
    digToDis[6][0] = 0, digToDis[6][1] = 1, digToDis[6][2] = 1, digToDis[6][3] = 1, digToDis[6][4] = 1, digToDis[6][5] = 1, digToDis[6][6] = 1;
    digToDis[7][0] = 1, digToDis[7][1] = 1, digToDis[7][2] = 0, digToDis[7][3] = 0, digToDis[7][4] = 0, digToDis[7][5] = 1, digToDis[7][6] = 0;
    digToDis[8][0] = 1, digToDis[8][1] = 1, digToDis[8][2] = 1, digToDis[8][3] = 1, digToDis[8][4] = 1, digToDis[8][5] = 1, digToDis[8][6] = 1;
    digToDis[9][0] = 1, digToDis[9][1] = 1, digToDis[9][2] = 1, digToDis[9][3] = 0, digToDis[9][4] = 1, digToDis[9][5] = 1, digToDis[9][6] = 1;


    cin >> T;

    while(T--)
    {
        cin >> v;
        x = v/10;
        y = v%10;

        if(x != 1 && digToDis[x][0] == digToDis[y][4] && digToDis[x][1] == digToDis[y][3])
            cout << cnt[x] + cnt[y] - digToDis[x][0] - digToDis[x][1] << "\n";
        else
            cout << cnt[x] + cnt[y] << "\n";
    }
}

