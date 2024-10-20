#include <bits/stdc++.h>
using namespace std;

#define ll long long

void sumOf(ll n, vector<ll> nums, ll target)
{

    sort(nums.begin(), nums.end());

    ll low = 0, high = n - 1;

    while (low < high)
    {

        ll sum = nums[low] + nums[high];

        if (sum == target)
        {
            cout << low + 1 << " " << high + 1;
            return;
        }
        else if (sum < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, target;
    cin >> n >> target;
    if (target == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<ll> nums(n);
    unordered_map<ll, ll> mp;
    mp.reserve(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (auto it = mp.find(target - nums[i]); it != mp.end())
        {
            cout << it->second + 1 << " " << i + 1;
            return 0;
        }
        mp[nums[i]] = i;
    }
    // sumOf(n, nums, target);
    cout << "IMPOSSIBLE";
    return 0;
}