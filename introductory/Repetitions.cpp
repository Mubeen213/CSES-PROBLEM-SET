
#include<bits/stdc++.h>
using namespace std;

/**
 *         // if(mp.find(charAt) == mp.end()) {
        //     mp.clear();
        // }
        // mp[charAt]++;
        // lenght = max(lenght, (int)mp[charAt]);
 */

// This has a TC of n**2 in worst case where there are all unique characters
// in worst case left might move uptill right
void lengthOfLongestRepetition(string s) {
    int left = 0, right=0;
    int lenght = 0;

    for(right=0; right<s.size(); right++) {
        while (left <= right && s[left] != s[right])
        {
            left++;
        }
        lenght = max(lenght, right-left+1);
    }
    cout<<lenght<<" ";
}

void lengthEffecient(string s) {

    int currLen = 1, maxLen = 1;

    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1]) {
            currLen++;
            maxLen = max(maxLen, currLen);
        } else {
            currLen = 1;
        }
    }
    cout<<(maxLen)<<" ";
}

int main() {
    string s;
    cin>>s;
    lengthEffecient(s);
}