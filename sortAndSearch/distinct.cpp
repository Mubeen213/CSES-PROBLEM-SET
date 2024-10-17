#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(NULL);
    ll n;
    scanf("%lld", &n);
    vector<ll> nums(n);
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll num;
        scanf("%lld", &num);
        st.insert(num);
    }
    cout << (int)st.size() << "\n";
}