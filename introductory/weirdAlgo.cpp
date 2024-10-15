#include <bits/stdc++.h>
using namespace std;

/*https://cses.fi/problemset/task/1068*/

/**
 * 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * 4 -> 2 -> 1
 *
 * 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * 6 -> 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * 7 -> 22 -> 11 -> 34 -> 17 -> 52 and so on
 *
 *
 */
/*
Thinking in terms of power of 2
*/

bool isPowerOftwo(long long n)
{
    return ((n & (n - 1)) == 0);
}

void solveForPowerOf2(long long n)
{
    while (n != 1)
    {
        n = (n >> 1);
        cout << n << " ";
    }
}

void simulateWeirdAlgo(long long n)
{

    unordered_map<long, long> memo;

    while (n != 1)
    {
        if (memo.find(n) != memo.end())
        {
            cout << memo[n] << " ";
            continue;
        }
        if (isPowerOftwo(n))
        {
            solveForPowerOf2(n);
            break;
        }
        long long next;
        if ((n & 1) == 0)
        {
            next = (n >> 1);
        }
        else
        {
            next = (n << 1) + n + 1;
        }
        memo[n] = next;
        cout << next << " ";
        n = next;
    }
}

int main()
{
    long long n;
    cin >> n;
    cout << n << " ";
    simulateWeirdAlgo(n);
}