#include<bits/stdc++.h>
using namespace std;

int curr_dir[3], all_dir[100009][3];

void plusY()
{
    if(curr_dir[2])
        return;

}

int main()
{
    int l;

    while(cin >> l)
    {
        if(!l)
            break;

        curr_dir[0] = 1;
        curr_dir[1] = 0;
        curr_dir[2] = 0;

        for(i = l-1; i > 0; i--)
        {
            cin >> dir;
            if(dir == "+y")
            {
                all_dir[i][0] = 0;
                all_dir[i][1] = 1;
                all_dir[i][2] = 0;
            }
            if(dir == "-y")
            {
                all_dir[i][0] = 0;
                all_dir[i][1] = -1;
                all_dir[i][2] = 0;
            }
            if(dir == "+z")
            {
                all_dir[i][0] = 0;
                all_dir[i][1] = 0;
                all_dir[i][2] = 1;
            }
            if(dir == "-z")
            {
                all_dir[i][0] = 0;
                all_dir[i][1] = 0;
                all_dir[i][2] = -1;
            }
        }

        for(i = 1; i < l; i++)
        {
            curr_dir
        }
    }
}
