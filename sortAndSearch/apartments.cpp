#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://cses.fi/problemset/task/1084

/**
 * Example
Input:
4 3 5
60 45 80 60
30 60 75
Output:
2
 */

void printA(vector<ll> nums)
{
    for (ll num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

void solve(ll n, ll m, ll k, vector<ll> apartments, vector<ll> apartSize)
{

    sort(apartments.begin(), apartments.end());
    sort(apartSize.begin(), apartSize.end());
    ll apartIdx = 0, sizeIdx = 0;
    int assigned = 0;

    while (apartIdx < n && sizeIdx < m)
    {
        int lowerRange = apartments[apartIdx] - k;
        int upperRange = apartments[apartIdx] + k;

        if (apartSize[sizeIdx] >= lowerRange && apartSize[sizeIdx] <= upperRange)
        {
            assigned++;
            apartIdx++;
            sizeIdx++;
        }
        else if (apartSize[sizeIdx] < lowerRange)
        {
            sizeIdx++;
        }
        else
        {
            apartIdx++;
        }
    }
    cout << assigned;
}

int main()
{

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> apartments(n), apartSize(m);

    for (int i = 0; i < n; i++)
    {
        cin >> apartments[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> apartSize[i];
    }
    solve(n, m, k, apartments, apartSize);
}