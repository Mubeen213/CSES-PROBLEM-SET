#include<bits/stdc++.h>
using namespace std;
#define ll long long

// https://cses.fi/problemset/task/1619

void print(vector<pair<ll, ll>> times) {

    for(auto p: times) {
        cout<<p.first << " ";
    }
    cout<<endl;
    for(auto p : times) {
        cout<<p.second<<" ";
    }
    cout<<endl;
}

// wrong approach
    void maxGuests(ll n, vector<pair<ll, ll>> times)
{
    sort(times.begin(), times.end());
    print(times);

    ll left = 0, right = 1;

    ll maxGuests = 1;

    while(left<n && right < n) {

        auto [arrival, leave] = times[left];
        ll guests = 1;
        while(right<n && leave > times[right].first) {
            right++;
            guests++;
        }
        left++;
        right++;
        maxGuests = max(guests, maxGuests);
    }
    cout<<maxGuests<<"\n";
}

void maxGuests(ll n, vector<pair<ll, int>> &events)
{
    sort(events.begin(), events.end(), [](const auto &a, const auto&b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    ll currentGuests = 0;
    ll maxGuests = 0;

    for (const auto &[time, event] : events)
    {
        currentGuests += event;
        maxGuests = max(maxGuests, currentGuests);
    }

    cout << maxGuests << "\n";
}

int main() {

    ll n;
    cin >> n;
    vector<pair<ll, int>> events;
    for(ll i=0; i<n; i++) {
        int x , y;
        cin>>x>>y;
        // times.push_back(make_pair(x, y));
        events.emplace_back(x, 1);
        events.emplace_back(y, -1);
    }
    maxGuests(n, events);
    return 0;
}