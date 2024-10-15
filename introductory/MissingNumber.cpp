#include<bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1083

/**
 * 5
 * 2 3 1 5
 * 1 2 3 4 5
 * 
 */

void missingNumber(int n, vector<int> nums) {
    
    int res = 0;

    for(int i=1; i<=n; i++) {
        res = res ^ i;
    }

    for(int i=0; i<nums.size(); i++) {
        res = res ^ nums[i];
    }
    cout<<res<<" ";
}
int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=1; i<n; i++) {
        int x; cin>>x;
        nums.push_back(x);
    }
    missingNumber(n, nums);
}