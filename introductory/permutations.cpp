#include <bits/stdc++.h>
using namespace std;

/*

5 -> 1 2 3 4 5
o -> 3 1 4 2 5

4 -> 1 2 3 4
4/2 = 2 =>
3 1 4 2

*/

void beautifulPermutation(int n)
{
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION ";
        return;
    }

    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    beautifulPermutation(n);
}