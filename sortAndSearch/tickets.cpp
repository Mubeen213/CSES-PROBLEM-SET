#include <iostream>
#include <vector>
#include <set>       // For multiset
#include <algorithm> // For sort
using namespace std;

typedef long long ll;

void purchase(ll n, ll m, multiset<ll> &priceSet, vector<ll> &customers)
{
    for (ll i = 0; i < m; i++)
    {
        auto it = priceSet.upper_bound(customers[i]);

        if (it == priceSet.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            --it;
            cout << *it << "\n";
            priceSet.erase(it);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m; // Input number of tickets and customers
    vector<ll> prices(n), customers(m);
    multiset<ll> priceSet; // Use multiset to maintain ticket prices

    for (ll i = 0; i < n; i++)
    {
        cin >> prices[i];
        priceSet.insert(prices[i]); // Insert price into multiset
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> customers[i]; // Input customers' offers
    }

    purchase(n, m, priceSet, customers); // Call purchase function
    return 0;
}
