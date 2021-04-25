/*---------------Go Code GO---------------*/

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using Order_Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//(order) Set.order_of_key(); (pointer) Set.find_by_order();

#define PI acos(-1.0)
#define O_O                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define precision(a) fixed << setprecision(a)
#define endl '\n'
#define Flush cout << flush
#define LLMX 0x3fffffffffffffff

int csno = 1;
bitset<2000006> isPrime;
vector<long long> primes;
void Sieve()
{
    primes.push_back(2);
    for (long long i = 3; i <= 2000000; i += 2)
    {
        if (isPrime[i] == 0)
        {
            primes.push_back(i);
            for (long long j = i * i; j <= 2000000; j += 2 * i)
                isPrime[j] = 1;
        }
    }
}
void Solution();

int main()
{
    O_O;
    Sieve();
    //cout << primes.back() << endl;
    int test = 1;
    cin >> test;
    while (test--)
    {
        Solution();
    }

    return 0;
}

void Solution()
{
    long long A, B;
    long long M;
    cin >> A >> B >> M;
    long long K = B - A;
    if (A == B)
    {
        cout << "Case " << csno++ << ": 0" << endl;
        return;
    }
    if (K == 1)
    {
        cout << "Case " << csno++ << ": " << M + 1 << endl;
        return;
    }
    vector<long long> Pfact;
    for (int i = 0; primes[i] * primes[i] <= K; i++)
    {
        int power = 0;
        while (K % primes[i] == 0)
        {
            K /= primes[i];
            power++;
        }
        if (power > 0)
            Pfact.push_back(primes[i]);
    }
    if (K > 1)
        Pfact.push_back(K);
    long long ans = 0;
    long long pms = Pfact.size();
    long long mask = (1LL << pms);
    long long L = A, R = A + M;
    for (long long i = 1; i < mask; i++)
    {
        long long multiple = 1;
        int cnt = 0;
        for (int j = 0; j < pms; j++)
        {
            if (i & (1LL << j))
            {
                multiple *= Pfact[j];
                cnt++;
            }
        }
        // cout << multiple << endl;
        long long numbers = R / multiple - (L - 1) / multiple;
        if (cnt & 1LL)
            ans -= numbers;
        else
            ans += numbers;
    }

    ans = R - L + 1 + ans;
    cout << "Case " << csno++ << ": " << ans << endl;
}
