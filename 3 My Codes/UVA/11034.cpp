#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, l, m, i, bank, car_len, ferry;
    int ans;
    string s;

    cin >> c;

    while(c--)
    {
        cin >> l >> m;
        l *= 100;

        queue<int> cars[2];

        for(i = 0; i < m; i++)
        {
            cin >> car_len >> s;

            if(s == "left")
                cars[0].push(car_len);
            else
                cars[1].push(car_len);
        }

        bank = 0;
        ans = 0;

        while(!cars[0].empty() || !cars[1].empty())
        {
            ferry = 0;

            while(!cars[bank].empty() && ferry + cars[bank].front() <= l)
            {
                ferry += cars[bank].front();
                cars[bank].pop();
            }

            ans++;
            bank = bank ^ 1;
        }

        cout << ans << "\n";
    }
}
