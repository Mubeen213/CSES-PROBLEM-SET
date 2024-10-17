#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printA(vector<ll> nums)
{
    for (ll num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}
void minNumberOfGondalas(ll n, ll x, vector<ll> weights)
{

    sort(weights.begin(), weights.end());
    // printA(weights);

    ll gondalas = 0;
    ll currWeight = 0;

    ll i = 0, j = n - 1;
    while (i <= j)
    {
        currWeight = weights[i] + weights[j];
        if (currWeight <= x)
        {
            i++;
        }
        j--;
        gondalas++;
    }
    cout << gondalas;
}

int main()
{

    ll n, x;
    cin >> n >> x;
    vector<ll> weights(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    minNumberOfGondalas(n, x, weights);
}