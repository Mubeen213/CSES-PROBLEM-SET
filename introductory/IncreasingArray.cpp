
#include<bits/stdc++.h>
using namespace std;

/**
 * 3 2 5 1 5
 * 3 3 5 1 5 -> 1
 * 
 * 
 */

void minMoves(int n, vector<long long > nums) {

    long long moves = 0;

    for(int i=1; i<n; i++) {

        if(nums[i] < nums[i-1] ) {
            moves += (nums[i-1] - nums[i]);
            nums[i] = nums[i-1];
        }
    }
    cout<<moves <<" ";
}

void acceptInput() {
    int n;
    cin >> n;
    vector<long long > nums;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        nums.push_back(x);
    }
    minMoves(n, nums);
}

int main() {
    acceptInput();
}