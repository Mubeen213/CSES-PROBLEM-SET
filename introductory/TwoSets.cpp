#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
 * https://cses.fi/problemset/task/1092
 *
 * Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
 * 7 (1 2 3 4 5 6 7)
 * YES
 * 4
 * 1 2 4 7  (14)
 * 3
 * 3 5 6 (14)
 *
 */

/**
### Understanding the DP Table

In the DP table, each entry `dp[i][j]` represents whether it is possible to achieve the sum `j` using the first `i` numbers from the set. The numbers in our set are `1` to `n`.

- If `dp[i][j] == 1`, it means that **it is possible to achieve the sum `j` using the first `i` numbers**.
- If `dp[i][j] == 0`, it means that **it is not possible to achieve the sum `j` using the first `i` numbers**.

### Extraction Logic

Now, let’s analyze the extraction logic and why we are doing it this way:

1. **Condition Check**:
   - When you check `if (dp[n - 1][targetSum] == 1)`, it means that you **can achieve the `targetSum` without using the number `n`**.
   - Therefore, you do not add `n` to the subset and just decrement `n` to check the next number.

2. **Including the Number**:
   - If `dp[n - 1][targetSum]` is not `1`, it means you **cannot achieve the `targetSum` without including the number `n`**.
   - Hence, you include `n` in your subset, decrease the `targetSum` by `n`, and continue checking.

### Why Do It This Way?

This logic allows you to effectively trace back through the choices made to form the target sum:

- **Excluding a Number**: If you can still achieve the `targetSum` without it, that means you made a choice in the DP process not to include it.
- **Including a Number**: If you can’t achieve the `targetSum` without it, it was a necessary choice, so you include it in the resulting subset.

### Visualization of the Logic

Let’s illustrate this with an example using the DP table for `n = 4` and `targetSum = 5`:

```
      0   1   2   3   4   5
  4  -1   1   1   1  -1   1
  3  -1   1   1   1  -1   1
  2  -1   1   1  -1  -1   0
  1  -1   1   0  -1  -1   0
```

### Extraction Steps Recap

- **Start with `n = 4` and `targetSum = 5`**.
- Check `dp[3][5]` (can you achieve `5` using numbers `1`, `2`, `3`?):
  - Yes → **Exclude `4`** (no inclusion), decrement `n` to `3`.
- Check `dp[2][5]`:
  - Yes → **Exclude `3`**, decrement `n` to `2`.
- Check `dp[1][5]`:
  - No → **Include `2`** in the subset, now check with `targetSum = 3` (i.e., `5 - 2`).
- Check `dp[0][3]`:
  - No → **Include `1`** in the subset.

### Final Summary

The extraction process effectively follows the choices made during the DP table filling, which reflects the logic behind whether a number was necessary to achieve the `targetSum`. This approach ensures that the resulting subset will indeed sum to the target.

If you have any more questions or need further clarification, feel free to ask!
 */

void printDpTable(int n, int targetSum, vector<vector<ll>> &dp)
{
    cout << "    ";
    for (int j = 0; j <= targetSum; j++)
    {
        cout << setw(3) << j << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << setw(3) << i << " ";
        for (int j = 0; j <= targetSum; j++)
        {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void findSubset(int n, int targetSum, vector<vector<ll>> &dp, unordered_set<int> &subset1)
{
    while (n > 0 && targetSum > 0)
    {
        // If we have not taken this element, move to dp[n-1][targetSum]
        if (dp[n - 1][targetSum] == 1)
        {
            n--;
        }
        // If we have taken this element, subtract its value and move to dp[n-1][targetSum - n]
        else
        {
            subset1.insert(n);
            targetSum -= n;
            n--;
        }
    }
}

bool findTargetSum(int n, int sum, vector<vector<ll>> &dp)
{

    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    int notPick = findTargetSum(n - 1, sum, dp);
    int pick = false;
    if (sum >= n)
    {
        pick = findTargetSum(n - 1, sum - n, dp);
    }
    return dp[n][sum] = pick || notPick;
}

void divideIntoSets(int n)
{
    ll totalSum = (n * (n + 1) / 2);

    if ((totalSum & 1) != 0)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    // find a subset whose sum is totalSum/2;
    ll targetSum = (totalSum >> 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(targetSum + 1, -1));

    findTargetSum(n, targetSum, dp);
    unordered_set<int> subset1;
    unordered_set<int> subset2;
    findSubset(n, targetSum, dp, subset1);

    for (int i = 1; i <= n; i++)
    {
        if (subset1.find(i) == subset1.end())
        {
            subset2.insert(i);
        }
    }
    cout << subset1.size() << "\n";
    for (auto it : subset1)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << subset2.size() << "\n";
    for (auto it : subset2)
    {
        cout << it << " ";
    }
    cout << "\n";
}

// Solution expects us to solve in O(n) TC
// trying greedy

/**
 * https://cses.fi/problemset/task/1092
 *
 * Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
 * 7 (1 2 3 4 5 6 7)
 * YES
 * 4
 * 1 2 4 7  (14)
 * 3
 * 3 5 6 (14)
 *
 */

/**
 * This works correctly
 */
void divideIntoSubsets(int n)
{

    ll totalSum = (ll)n * (n + 1) / 2;

    if ((totalSum & 1) != 0)
    {
        cout << "NO\n";
        return;
    }

    ll targetSum = (totalSum >> 1);

    vector<int> set1, set2;
    int currSum = 0;
    for (int i = n; i >= 1; i--)
    {
        if (targetSum >= i)
        {
            set1.push_back(i);
            targetSum -= i;
        }
        else
        {
            set2.push_back(i);
        }
    }
    cout << "YES\n";
    cout << set1.size() << "\n";
    for (auto it : set1)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << set2.size() << "\n";
    for (auto it : set2)
    {
        cout << it << " ";
    }
    cout << "\n";
}

// The below one did not work
void divideInto(int n)
{

    ll totalSum = (ll)n * (n + 1) / 2;

    if ((totalSum & 1) != 0)
    {
        cout << "NO\n";
        return;
    }

    ll targetSum = (totalSum >> 1);
    cout << "Target Sum " << targetSum << " ";
    vector<int> set1, set2;
    // add into set 1 all values whose sum should be lesser than targetSum
    // k * (k+1) / 2 <= targetSum
    // k * (k+1) = 2 * targetSum
    // k^2 = 2 * targetSum
    // k = sqrt(2 * targetSum);

    int k = sqrt(2 * targetSum);

    while (((ll)k * (k + 1)) > 2 * targetSum)
    {
        k--;
    }

    for (int i = 1; i <= k; i++)
    {
        set1.push_back(i);
    }
    ll sumOfFirstK = (ll)k * (k + 1) / 2;
    cout << "Sum " << sumOfFirstK << "\n";

    cout << "YES\n";
    int remainingSumNeended = (targetSum - sumOfFirstK);
    cout << (k + remainingSumNeended > 0 ? 1 : 0) << " ";
    if (sumOfFirstK < targetSum)
    {
        set1.push_back(remainingSumNeended);
    }

    for (int i = k + 1; i <= n; i++)
    {
        if (i != remainingSumNeended)
        {
            set2.push_back(i);
        }
    }

    cout << set1.size() << "\n";
    for (auto it : set1)
    {
        cout << it << " ";
    }
    cout << "\n";
    cout << set2.size() << "\n";
    for (auto it : set2)
    {
        cout << it << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    divideIntoSubsets(n);
}