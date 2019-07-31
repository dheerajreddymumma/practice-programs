//
//  main.cpp
//  palindrome_substring
//
//  Created by Dheeraj Reddy on 01/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int countSubstrings(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int count = 0;
    for(int i=0;i<s.size();i++) {
        dp[i][i] = 1;
        count++;
    }
    for(int i=1;i<s.size();i++) {
        for(int j=0;j<i;j++) {
            if(s[j] == s[i]) {
                if(j+1 == i || dp[i-1][j+1] == 1) {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

void findAllPermutations(vector<int>& nums, vector<vector<int>>& vec) {
    vec.push_back(nums);
    int lastIndex = nums.size() - 1;
    while(lastIndex > 0 && nums[lastIndex] < nums[lastIndex-1])
        lastIndex--;
    if(lastIndex > 0) {
        int findSmallestIndex = -1, smallestFoundInt = INT_MAX;
        for(int i=lastIndex;i<nums.size();i++) {
            if(nums[lastIndex-1] < nums[i] && nums[i] < smallestFoundInt) {
                findSmallestIndex = i;
                smallestFoundInt = nums[i];
            }
        }
        int temp = nums[findSmallestIndex];
        nums[findSmallestIndex] = nums[lastIndex-1];
        nums[lastIndex-1] = temp;
        sort(nums.begin()+lastIndex, nums.end());
        findAllPermutations(nums, vec);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> vec;
    if(nums.size() == 0)
        return vec;
    sort(nums.begin(), nums.end());
    findAllPermutations(nums, vec);
    return vec;
}


int main(int argc, const char * argv[]) {
//    string s;
//    cin >> s;
//    cout << countSubstrings(s);
    vector<int> v1 = {1,2,3};
    permute(v1);
    
    
    return 0;
}
