#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int board[55][55], n, r, c, visited[55][55];
int disx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int disy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

void print_board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << setw(5) << board[i][j];
        cout << "\n";
    }
}

bool circuit_check(int stx, int sty, int edx, int edy)
{
    for(int i = 0; i < 8; i++)
    {
        if(stx + disx[i] == edx && sty + disy[i] == edy)
            return 1;
    }
    return 0;
}

int solve(int x, int y, int cnt)
{
    print_board();
    cout << "-------------------------\n";

    board[x][y] = cnt;

    if(cnt == n*n && circuit_check(r, c, x, y))
    {
        print_board();
        return 1;
    }

    int i, j, new_x, new_y, ret = 0;
    //bfs start
    memset(visited, 0, sizeof visited);
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while(!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        for(i = 0; i < 8; i++)
        {
            new_x = node.ff + disx[i];
            new_y = node.ss + disy[i];
            if(is_valid(new_x, new_y) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(visited[i][j] == 0 && board[i][j] == -1)
                return 0;
        }
    }
    //bfs end


    for(i = 0; i < 8; i++)
    {
        new_x = x + disx[i];
        new_y = y + disy[i];
        if(is_valid(new_x, new_y) && ret == 0)
            ret = solve(new_x, new_y, cnt+1);
    }

    board[x][y] = -1;
    return ret;
}

int main()
{
    while(cin >> n >> r >> c)
    {
        r--;
        c--;
        memset(board, -1, sizeof board);

        if(solve(r, c, 1) == 0)
            cout << "No Circuit Tour.\n";

        cout << "\n";
    }
}

