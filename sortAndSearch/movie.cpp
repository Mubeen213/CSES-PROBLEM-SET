#include <bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<pair<ll, ll>> times)
{

    for (auto p : times)
    {
        cout << p.first << " ";
    }
    cout << endl;
    for (auto p : times)
    {
        cout << p.second << " ";
    }
    cout << endl;
}

void maxMovies(ll n, vector<pair<ll, ll>> movie)
{

    sort(movie.begin(), movie.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });
    // print(movie);

    ll maxWatch = 1;
    ll lastWatch = movie[0].second;
    for (ll i = 1; i < n; i++)
    {
        if (movie[i].first >= lastWatch)
        {
            maxWatch++;
            lastWatch = movie[i].second;
        }
    }
    cout << maxWatch;
}

int main()
{

    ll n;
    cin >> n;
    vector<pair<ll, ll>> movie;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        movie.emplace_back(a, b);
    }
    maxMovies(n, movie);
}